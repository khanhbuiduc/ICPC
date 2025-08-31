#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
using namespace std;
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
int t, p, sum = 0;
int a[205];
set<int> adj[205];

vector<int> topo;
bool visited[205];

int f[205];
/// template
void initial()
{
    cin >> t >> p;
    FOR(i, 0, t - 1)
    {
        cin >> a[i];
        sum += a[i];
    }
    string line;
    getline(cin, line);
    while (getline(cin, line) && line != "{}")
    {
        int u = line.back() - '0';
        int i = 1;
        while (isdigit(line[i]))
        {
            int v = line[i] - '0';
            adj[v].insert(u);
            i += 3;
        }
    }
}

void dfs_topo(int u)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs_topo(v);
    topo.push_back(u);
}
void solve()
{
    // ta có thứ tự topo;
    FOR(u, 0, t)
    {
        if (!visited[u])
            dfs_topo(u);
    }
    reverse(topo.begin(), topo.end());

    // longest_path
    int longest_path = 0;
    for (int u : topo)
    {
        maximize(f[u], a[u]);
        for (int v : adj[u])
        {
            f[v] = max(f[v], f[u] + a[v]);
        }
    }
    FOR(u, 0, t - 1)
    maximize(longest_path, f[u]);
    int loadBound = (sum + p - 1) / p;
    cout << max(loadBound, longest_path);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    initial();
    solve();
}
// bài này sai