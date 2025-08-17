#include <bits/stdc++.h>
using namespace std;
bool visited[100005];
vector<int> adj[100005];
int f[100005];
stack<int> store;
int m, n;
void Topo(int u)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            Topo(v);
    store.push(u);
}
int main()
{
    // khởi tạo
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // topo sort
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            Topo(i);
    // dp
    int res = 0;
    while (!store.empty())
    {
        u = store.top();
        store.pop();
        for (int v : adj[u])
        {
            f[v] = max(f[v], f[u] + 1);
            res = max(res, f[v]);
        }
    }
    cout << res;
}

/*
cho 1 đồ thị DAG n đỉnh m cạnh. tìm đường đi qua nhiều cạnh nhất trong G.
 dùng DP:
    gọi f[u] là đường đi dài nhất khi gặp đỉnh u
    bài toán cơ sở: f[u]=0: u: 1->n
    công thức:
        xét đỉnh u:
            xét mọi v kề u.
                f[v]=max(f[v],f[u]+1);
    kết quả: max(f[u]) u: 1->n;
 h=nhưng nếu u->v; nhưng u duyệt sau v thì sai
store: lưu trữ thứ tự topo để duyệt dfs
*/