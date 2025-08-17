#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10'005];
int low[10'005], num[10'005], cntDfs = 0, ans = 0;
bool is_deleted[10'005];
int m, n;
int cnt = 0;
stack<int> store;
void dfs(int u)
{
    low[u] = num[u] = ++cntDfs;
    store.push(u);
    for (int v : adj[u])
    {
        if (is_deleted[v])
            continue;
        if (num[v] > 0)
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u])
    {
        ans++;
        while (true)
        {
            int v = store.top();
            store.pop();
            is_deleted[v] = true;
            if (v == u)
                break;
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
    }
    for (int i = 1; i <= n; i++)
        if (num[i] == 0)
            dfs(i);
    cout << ans;
}