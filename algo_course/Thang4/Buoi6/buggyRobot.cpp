#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tiii;
const int inf = 1'000'000'007;
int dist[55][55][55];
char a[55][55];
string command;
int dx[4] = {0, 0, 1, -1}; // R,L,D,U
int dy[4] = {1, -1, 0, 0};
map<char, int> direction = {{'R', 0}, {'L', 1}, {'D', 2}, {'U', 3}};
priority_queue<pair<int, tiii>, vector<pair<int, tiii>>, greater<pair<int, tiii>>> pq;
int n, m;
pair<int, int> s, e;

bool checkInOfBound(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void dijkstra()
{
    // Khởi tạo khoảng cách
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k <= (int)command.length(); k++)
                dist[i][j][k] = inf;

    dist[s.first][s.second][0] = 0;
    pq.push({0, {s.first, s.second, 0}});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        auto [x, y, p] = u;

        // Kiểm tra đến đích
        if (x == e.first && y == e.second)
        {
            cout << d << endl;
            return;
        }

        if (d > dist[x][y][p])
            continue;

        // 1. Bỏ qua lệnh hiện tại (xóa lệnh - cost = 1)
        if (p < (int)command.length() && dist[x][y][p + 1] > dist[x][y][p] + 1)
        {
            dist[x][y][p + 1] = dist[x][y][p] + 1;
            pq.push({dist[x][y][p + 1], {x, y, p + 1}});
        }

        // 2. Thêm lệnh di chuyển mới (cost = 1, position không đổi)
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!checkInOfBound(nx, ny) || a[nx][ny] == '#')
            {
                nx = x;
                ny = y;
            }
            if (checkInOfBound(nx, ny) && a[nx][ny] == '.' && dist[nx][ny][p] > dist[x][y][p] + 1)
            {
                dist[nx][ny][p] = dist[x][y][p] + 1;
                pq.push({dist[nx][ny][p], {nx, ny, p}});
            }
        }

        // 3. Sử dụng lệnh có sẵn (cost = 0)
        if (p < (int)command.length())
        {
            int dir = direction[command[p]]; // Sử dụng command[c], không phải command[c+1]
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // Xử lý va chạm: nếu gặp tường hoặc ra ngoài thì đứng yên
            if (!checkInOfBound(nx, ny) || a[nx][ny] == '#')
            {
                nx = x;
                ny = y;
            }

            if (dist[nx][ny][p + 1] > dist[x][y][p])
            {
                dist[nx][ny][p + 1] = dist[x][y][p];
                pq.push({dist[nx][ny][p + 1], {nx, ny, p + 1}});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = temp[j - 1];
            if (temp[j - 1] == 'R')
                s = {i, j};
            if (temp[j - 1] == 'E')
                e = {i, j};
        }
    }
    cin >> command;
    dijkstra();
    return 0;
}