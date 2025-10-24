#include <bits/stdc++.h>
using namespace std;
bool visited[25][25];
string maze[25];
int t, n, m;
int res = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt = 0;
int sx = 0, sy = 0, ex = 0, ey = 0;
bool updateStartEnd(int x, int y)
{
    cnt++;
    if (cnt == 1)
    {
        sx = x;
        sy = y;
        return true;
    }
    if (cnt == 2)
    {
        ex = x;
        ey = y;
        return true;
    }
    return false;
}
bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    if (visited[x][y])
        return false;
    return maze[x][y] == '.';
}
void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i <= 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!check(nx, ny))
            continue;
        dfs(nx, ny);
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> maze[i];
        // reset
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        // kiểm tra 4 cạnh biên có đúng 2 đầu ra;
        for (int j = 0; j < m; j++)
        {
            if (maze[0][j] == '.' && !updateStartEnd(0, j))
                break;
            if (n != 1 && maze[n - 1][j] == '.' && !updateStartEnd(n - 1, j))
                break;
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (maze[i][0] == '.' && !updateStartEnd(i, 0))
                break;
            if (m != 1 && maze[i][m - 1] == '.' && !updateStartEnd(i, m - 1))
                break;
        }
        if (cnt != 2)
        {
            cout << "invalid" << endl;
            continue;
        }
        // tìm xem liệu sx,sy có tìm đc ex,ey;
        dfs(sx, sy);
        cout << (visited[ex][ey] ? "valid" : "invalid") << endl;
    }
}