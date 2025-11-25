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
int root[200'005];
vector<pii> adj[200'005];
vector<tiii> store;
bool visited[200'005];
int findRoot(int u)
{
    return (root[u] = (root[u] == u) ? u : findRoot(root[u]));
}
void setUnion(int u, int v)
{
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv)
    {
        root[rootu] = rootv;
    }
}
void dfs(int u)
{
    visited[u] = true;
    for (auto [v, w] : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        store.emplace_back(w, u, v);
    }
    // kiểm tra xem tất cả các đỉnh có chung tplt không.
    dfs(1);
    FOR(i, 1, n)
    {
        if (!visited[i])
        {
            cout << -1;
            return 0;
        }
    }
    // kruskal
    sort(ALL(store));
    FOR(i, 1, n) { root[i] = i; }
    ll total = 0;
    // duyệt từng cạnh kiểm tra dsu
    for (auto [w, u, v] : store)
    {
        int rootu = findRoot(u);
        int rootv = findRoot(v);
        if (rootu == rootv)
            continue;
        else
        {
            setUnion(u, v);
            total += w;
        }
    }
    cout << total;
}