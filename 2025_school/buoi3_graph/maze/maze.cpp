#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
pii s;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};
char a[1005][1005];
int trace[1005][1005];
queue<pii> myqueue;
bool OutOfBound(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return true;
    return false;
}
bool checkEnd(int x, int y)
{
    if (x == 1 || x == n || y == 1 || y == m)
        return true;
    return false;
}
void printTrace(int x, int y)
{
    string path = "";
    while (!(x == s.ff && y == s.ss))
    {
        int d = trace[x][y];
        path += dir[d];
        x -= dx[d];
        y -= dy[d];
    }
    reverse(path.begin(), path.end());
    cout << path << endl;
}
void initial()
{
    cin >> n >> m;
    FOR(i, 1, n)
    FOR(j, 1, m)
    {
        cin >> a[i][j];
        if (a[i][j] == 'E')
            s = {i, j};
    }
}
void solve()
{
    myqueue.push(s);
    while (!myqueue.empty())
    {
        auto [x, y] = myqueue.front();
        myqueue.pop();
        FOR(d, 0, 3)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (OutOfBound(nx, ny))
                continue;
            if (a[nx][ny] == 'O')
            {
                myqueue.push({nx, ny});
                a[nx][ny] = 'E';
                trace[nx][ny] = d;
                if (checkEnd(nx, ny))
                {
                    printTrace(nx, ny);
                    return;
                }
            }
        }
    }
    cout << "no solution";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    initial();
    solve();
    return 0;
}