#include <bits/stdc++.h>
using namespace std;
bool visited[100005];
vector<int> adj[200005]; // thứ tự màu
int num[100005], low[100005];
int timeDFS = 0;
vector<pair<int, int>> bridges;
set<int> joints;
int n, m;
// tìm khớp:
void dfs(int u, int father)
{
    num[u] = low[u] = ++timeDFS;
    int children = 0;
    for (int v : adj[u])
    {
        if (v == father) // không xét father
            continue;
        else if (num[v] > 0) // nếu v đã duyệt
            low[u] = min(low[u], num[v]);
        else // nếu chưa duyệt
        {
            dfs(v, u);
            children++;
            low[u] = min(low[u], low[v]);
            if (u == 1 && children >= 2)
                joints.insert(u);
            if (u != 1 && low[v] >= num[u])
                joints.insert(u);
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
    for (int i = 1; i <= n; i++)
        if (num[i] == 0)
            dfs(i, -1);
    cout << joints.size() << endl;
    for (int joint : joints)
    {
        cout << joint << ' ';
    }
}