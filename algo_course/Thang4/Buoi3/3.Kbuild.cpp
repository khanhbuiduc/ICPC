#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
int num[200005], low[200005];
int timeDFS = 0;
vector<pair<int, int>> bridges;
unordered_set<long long> repair; // Thay thế unordered_map array
int n, m;

void dfs(int u, int father)
{
    num[u] = low[u] = ++timeDFS;
    for (int v : adj[u])
    {
        if (v == father)
            continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) // Sửa điều kiện tìm cầu
            {
                // Kiểm tra có phải cạnh repair không
                int a = min(u, v), b = max(u, v);
                long long edge = (long long)a * 200005 + b;
                if (repair.find(edge) == repair.end())
                    bridges.emplace_back(u, v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // Lưu cạnh repair với hash
        int a = min(u, v), b = max(u, v);
        repair.insert((long long)a * 200005 + b);
    }
    dfs(1, 0);
    cout << bridges.size() << endl;
}