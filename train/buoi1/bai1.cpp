#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[100'005];
stack<int> topo;
int visited[100'005];
bool haveCircle = false;
int state[100'005];
void dfs_DAG(int u)
{
    if (haveCircle)
        return;
    state[u] = 1;
    for (auto v : adj[u])
    {
        if (state[v] == 0)
        {
            dfs_DAG(v);
        }
        if (state[v] == 1)
        {
            haveCircle = true;
            return;
        }
    }
    state[u] = 2;
}
void dfs(int u)
{
    visited[u] = true;
    for (auto v : adj[u])
        if (!visited[v])
            dfs(v);
    topo.push(u);
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // kiểm tra đồ thị có chu trình không
    FOR(u, 1, n)
    {
        if (!state[u])
        {
            dfs_DAG(u);
        }
    }
    if (haveCircle)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    FOR(u, 1, n)
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
    while (!topo.empty())
    {
        cout << topo.top() << ' ';
        topo.pop();
    }
}
