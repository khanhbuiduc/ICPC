#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tiii;
const int inf = 1e9;

int n, m;
vector<vector<int>> dist;
vector<vector<char>> a;
priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool checkInOfBound(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void dijkstra()
{
    bool found = false;

    while (!pq.empty())
    {
        auto [d, x, y] = pq.top();
        pq.pop();

        if (d != dist[x][y])
            continue;

        // Kiểm tra đến đích (biên trên hoặc biên phải)
        if (x == 1 || y == m)
        {
            cout << d << endl;
            found = true;
            return;
        }

        for (int dir = 0; dir < 8; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!checkInOfBound(nx, ny) || a[nx][ny] == '@')
                continue;

            // Cost: '.' = 1 (cần block), '#' = 0 (không cần block)
            int w = (a[nx][ny] == '.') ? 1 : 0;
            int new_dist = dist[x][y] + w;

            if (new_dist < dist[nx][ny])
            {
                dist[nx][ny] = new_dist;
                pq.emplace(new_dist, nx, ny);
            }
        }
    }

    if (!found)
    {
        cout << -1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m && (n != 0 || m != 0))
    {
        // Khởi tạo
        a.assign(n + 1, vector<char>(m + 1));
        dist.assign(n + 1, vector<int>(m + 1, inf));

        // Clear priority queue
        while (!pq.empty())
            pq.pop();
        // Đọc input
        for (int i = 1; i <= n; i++)
        {
            string row;
            cin >> row;
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = row[j - 1];
            }
        }

        // Khởi tạo điểm xuất phát - biên trái (cột 1)
        for (int i = 1; i <= n; i++)
        {
            if (a[i][1] == '.')
            {
                dist[i][1] = 1;
                pq.emplace(1, i, 1);
            }
            else if (a[i][1] == '#')
            {
                dist[i][1] = 0;
                pq.emplace(0, i, 1);
            }
            // '@' không được thêm vào pq
        }

        // Khởi tạo điểm xuất phát - biên dưới (hàng n)
        for (int j = 2; j <= m; j++)
        { // j=2 để tránh duplicate (n,1)
            if (a[n][j] == '.')
            {
                dist[n][j] = 1;
                pq.emplace(1, n, j);
            }
            else if (a[n][j] == '#')
            {
                dist[n][j] = 0;
                pq.emplace(0, n, j);
            }
            // '@' không được thêm vào pq
        }

        dijkstra();
    }

    return 0;
}