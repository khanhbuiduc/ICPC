#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n, s0;
int rec[200][200]; // 1 ≤ n ≤ 182, 1 ≤ m ≤ 182
queue<pair<int, int>> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void printRetangular()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << rec[i][j] << ' ';
        }
        cout << endl;
    }
}
bool in_Bound(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}
// bfs
void bfs()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            rec[i][j] = rec[i][j] - 1;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir <= 3; dir++)
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (in_Bound(nx, ny) && rec[nx][ny] == -1)
            {
                rec[nx][ny] = rec[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        string row;
        for (int i = 1; i <= n; i++)
        {
            cin >> row;
            for (int j = 1; j <= m; j++)
            {
                rec[i][j] = row[j - 1] - '0';
                if (rec[i][j] == 1)
                    q.push({i, j});
            }
        }
        //
        bfs();
        //
        printRetangular();
    }
}