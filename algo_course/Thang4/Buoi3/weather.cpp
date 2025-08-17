#include <bits/stdc++.h>
using namespace std;
vector<int> adj[5005];
int num[105], low[105];
int timeDFS = 0;
vector<pair<int, int>> bridges;
int n, m;
int sz[105];
int ans = 0;
void dfs(int u, int father)
{
    num[u] = low[u] = ++timeDFS;
    sz[u] = 1;
    for (int v : adj[u])
    {
        if (v == father)
            continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v])
            {
                ans += (sz[v] * (n - sz[v]));
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans;
}