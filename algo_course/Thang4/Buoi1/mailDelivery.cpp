#include <bits/stdc++.h>
using namespace std;
bool visited[1005][1005];
set<int> adj[100005];
vector<int> ans;
int n, m;
void dfs(int u)
{
    while (!adj[u].empty())
    {
        int v = *adj[u].begin();
        adj[u].erase(v);
        adj[v].erase(u);
        dfs(v);
    }
    ans.push_back(u);
}
int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int u = 1; u <= n; u++)
    {
        if (adj[u].size() & 1)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    dfs(1);
    if (ans.size() != m + 1) // vì có trường hợp bậc chẵn những đồ thị không liên thông
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i : ans)
    {
        std::cout << i << ' ';
    }
}