#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const vector<pair<int, int>> directions = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int n, m, ax, ay, bx, by;
string maze[MAXN];
int dist[MAXN][MAXN][8];

int bfs()
{
    deque<tuple<int, int, int>> q;
    // Khởi tạo với tất cả hướng ban đầu
    for (int d = 0; d < 8; ++d)
    {
        q.emplace_back(ax, ay, d);
        dist[ax][ay][d] = 0;
    }
    // q.push_back({ax, ay, 0});
    // dist[ax][ay][0] = 0;
    int x, y, t, dx, dy;
    int i = 0;
    while (!q.empty())
    {
        auto [x, y, t] = q.front();
        q.pop_front();
        // Nếu đã đến được ô đích
        if (x == bx && y == by)
        {
            return dist[x][y][t % 8];
        }

        // Ở trạng thái hiện tại, chúng ta có thể chờ 1 giây
        int nt = t + 1;
        if (dist[x][y][nt % 8] == -1) // nếu vị trí ở ô, trạng thái chưa đi, thêm vào queue
        {
            dist[x][y][nt % 8] = nt;
            q.emplace_back(x, y, nt);
        }

        // Di chuyển theo hướng của nam châm tại thời điểm t
        int dir_idx = (maze[x][y] - '0' + t) % 8;
        auto [dx, dy] = directions[dir_idx];
        int nx = x + dx, ny = y + dy;

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && (dist[nx][ny][nt % 8] == -1 || dist[nx][ny][nt % 8] > nt))
        { // nếu nằm trong ma trận và (chưa đi hoặc distant nhỏ hơn)
            dist[nx][ny][nt % 8] = nt;
            q.emplace_back(nx, ny, nt);
        }
    }

    return -1; // Không tìm thấy đường ra
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("escape.inp", "r", stdin);
    freopen("escape.out", "w", stdout);
    cin >> n >> m;
    cin >> ax >> ay >> bx >> by;
    ax--, ay--, bx--, by--;

    for (int i = 0; i < n; ++i)
    {
        cin >> maze[i];
    }

    memset(dist, -1, sizeof(dist));
    int result = bfs();
    cout << result << '\n';

    return 0;
}
