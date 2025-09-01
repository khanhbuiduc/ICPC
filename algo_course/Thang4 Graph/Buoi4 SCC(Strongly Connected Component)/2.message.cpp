#include <bits/stdc++.h>
using namespace std;
vector<int> adj[805];
int low[805], num[805], cntDfs = 0, ans = 0;
bool is_deleted[805], haveIn[805];
int m, n;
int cnt = 0;
stack<int> store;
int root[805];

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
        while (true)
        {
            int v = store.top();
            store.pop();
            is_deleted[v] = true;
            root[v] = u;
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
    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
        {
            if (root[u] != root[v])
                haveIn[root[v]] = true;
        }
    for (int u = 1; u <= n; u++)
        if (u == root[u] && !haveIn[root[u]])
            ans++;
    cout << ans;
}
// sau khi phân nhóm thành các phần liên thông mạnh thì chắc chắn là đồ thị DAG. ta đếm xem có bao nhiêu thành phần liên thông mạnh mà k có nhóm khác hướng tới.