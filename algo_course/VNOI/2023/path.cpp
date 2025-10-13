#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n, t;
const int mod = 1'000'000'007;
int h[200'005];
vector<int> adj[200'005];
vector<pair<int, int>> adjPair;
int sz[200'005];
bool visited[200'005];
int root[200'005];
void dfs(int u, int max_h)
{
    visited[u] = true;
    sz[u] = 1;
    for (auto v : adj[u])
    {
        if (!visited[v] && h[v] <= max_h)
        {
            root[v] = root[u];
            dfs(v, max_h);
            sz[u] += sz[v];
        }
    }
}
int solve(int max_h)
{
    ll res = 0;
    memset(sz, 0, sizeof(sz));
    memset(root, 0, sizeof(root));
    memset(visited, false, sizeof(visited));
    // tính size
    FOR(u, 1, n)
    {
        if (!visited[u] && h[u] <= max_h)
        {
            root[u] = u;
            dfs(u, max_h);
        }
    }
    //
    for (auto [u, v] : adjPair)
    {
        if (h[u] > max_h || h[v] > max_h)
            continue;
        ll a = min(sz[u], sz[v]);
        ll b = sz[root[u]] - a;
        (res += (a * b * (b - 1) / 2)) %= mod;
        (res += (b * a * (a - 1) / 2)) %= mod;
    }
    return res;
}
int main()
{
    cin >> n >> t;
    FOR(i, 1, n)
    {
        cin >> h[i];
    }
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adjPair.push_back({u, v});
    }
    cout << (2 * ((solve(t) - solve(t - 1) + mod) % mod)) % mod;
}
// nhận  xét để đỡ sai. mọi hàm mod lên viết hàm ngoài.