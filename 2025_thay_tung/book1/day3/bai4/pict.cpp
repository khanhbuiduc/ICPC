#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
bool visted[1005][1005];
string a[1005];
int n, m;
bool outOfBound(int x, int y)
{
    return x < 0 && n <= x && y < 0 && m <= y;
}
void mark(int x, int y, vector<pii> &c)
{
    // kiểm tra x
    for (auto [dx, dy] : c)
    {
        int nx = x + dx, ny = y + dy;
        if (outOfBound(nx, ny))
            continue;
        if (a[nx][ny] == '.')
        {
            return;
        }
    }
    // đánh dấu x
    for (auto [dx, dy] : c)
    {
        int nx = x + dx, ny = y + dy;
        if (outOfBound(nx, ny))
            continue;
        visted[nx][ny] = true;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<pii> X = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    vector<pii> O = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
    cin >> n >> m;
    FOR(i, 0, n - 1)
    {
        cin >> a[i];
    }
    //
    FOR(i, 0, n - 1)
    FOR(j, 0, m - 1)
    {
        if (a[i][j] == '*')
        {
            mark(i, j, X);
            mark(i, j, O);
        }
    }
    FOR(i, 0, n - 1)
    FOR(j, 0, m - 1)
    {
        if (a[i][j] == '*' && !visted[i][j])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
