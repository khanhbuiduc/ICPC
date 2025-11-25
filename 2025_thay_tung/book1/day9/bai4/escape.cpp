#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int n, m, s_x, s_y, e_x, e_y;
string a[1005];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dist[1005][1005][8];

deque<tiii> q;

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve()
{
    FOR(i, 0, n - 1)
    FOR(j, 0, m - 1)
    FOR(t, 0, 7)
    {
        dist[i][j][t] = -1;
    }

    dist[s_x][s_y][0] = 0;
    q.push_back({s_x, s_y, 0});

    while (!q.empty())
    {
        auto [x, y, t] = q.front();
        q.pop_front();
        // nếu ở ô kết thúc
        if (x == e_x && y == e_y)
        {
            cout << dist[x][y][t];
            return;
        }
        // Nếu ở ô  ban đầu
        if (x == s_x && y == s_y)
        {
            int nt = t + 1;

            // Đứng yên
            if (dist[x][y][nt % 8] == -1)
            {
                dist[x][y][nt % 8] = nt;
                q.push_back({x, y, nt});
            }
            // Di chuyển theo 8 hướng chính: 4 bước xung quanh
            FOR(dir, 0, 7)
            {
                if (dir & 1)
                {
                    continue;
                }
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (isValid(nx, ny) && dist[nx][ny][nt % 8] == -1)
                {
                    dist[nx][ny][nt % 8] = nt;
                    q.push_back({nx, ny, nt});
                }
            }
        }
        else
        {
            int direction = (a[x][y] - '0' + t) % 8;
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (isValid(nx, ny))
            {
                if (dist[nx][ny][t % 8] == -1 || dist[nx][ny][t % 8] > t)
                {
                    dist[nx][ny][t % 8] = t;
                    q.push_front({nx, ny, t});
                }
            }
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s_x >> s_y >> e_x >> e_y;
    s_x--, s_y--, e_x--, e_y--;

    FOR(i, 0, n - 1)
    {
        cin >> a[i];
    }

    solve();
    return 0;
}
/*
bfs
topo
cầu khớp
thành phần liên thông mạnh// tajant
dijstras
BFS
DSU: kiểm tra 2 đỉnh chung tplt
-----------
*/