#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef long long ll;
int n, m;
char a[25][25];
bool visited[25][25][10];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x, int y, int pois)
{
    visited[x][y][pois] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (a[nx][ny] == '#')
            continue;
        if (isdigit(a[nx][ny]) && pois + (a[nx][ny] - '0') >= 10)
            continue;
        int nextpois = pois;
        if (a[nx][ny] == 'S')
            nextpois = 0;
        else if (isdigit(a[nx][ny]))
            nextpois += (a[nx][ny] - '0');
        if (visited[nx][ny][nextpois] == false)
            dfs(nx, ny, nextpois);
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        memset(visited, false, sizeof(visited));
        for (int j = 0; j <= m + 1; j++)
            a[0][j] = a[n + 1][j] = '#';
        for (int i = 1; i <= n; i++)
        {
            a[i][0] = a[i][m + 1] = '#';
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(1, 1, 0);
        bool ans = false;
        for (int pois = 0; pois < 10; pois++)
        {
            if (visited[n][m][pois])
            {
                ans = true;
                break;
            }
        }
        cout << (ans ? "possible" : "impossible") << endl;
    }
}