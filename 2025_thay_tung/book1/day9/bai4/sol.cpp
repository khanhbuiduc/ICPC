#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t3i;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int ax, ay;
    cin >> ax >> ay;
    --ax, --ay;

    int bx, by;
    cin >> bx >> by;
    --bx, --by;

    vector<string> s(n);
    for (auto &e : s)
        cin >> e;

    vector<pair<int, int>> dir{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(8, -1)));
    dist[ax][ay][0] = 0;

    deque<t3i> q;
    q.push_back({ax, ay, 0});

    while (!q.empty())
    {
        auto [cx, cy, t] = q.front();
        q.pop_front();

        if (s[cx][cy] == '.')
        {
            int nt = t + 1;
            if (dist[cx][cy][nt % 8] == -1)
            {
                dist[cx][cy][nt % 8] = nt;
                q.push_back({cx, cy, nt});
            }

            for (int i = 0; i < 8; i += 2)
            {
                auto [dx, dy] = dir[i];
                int nx = cx + dx;
                int ny = cy + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (dist[nx][ny][nt % 8] == -1)
                {
                    dist[nx][ny][nt % 8] = nt;
                    q.push_back({nx, ny, nt});
                }
            }
        }
        else
        {
            int i = (s[cx][cy] - '0' + t) % 8;
            auto [dx, dy] = dir[i];
            int nx = cx + dx;
            int ny = cy + dy;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (dist[nx][ny][t % 8] == -1 || dist[nx][ny][t % 8] > t)
            {
                dist[nx][ny][t % 8] = t;
                q.push_front({nx, ny, t});
            }
        }
    }

    cout << *min_element(dist[bx][by].begin(), dist[bx][by].end());
    return 0;
}