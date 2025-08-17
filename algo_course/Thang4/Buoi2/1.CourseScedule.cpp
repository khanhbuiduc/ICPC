#include <bits/stdc++.h>
using namespace std;
bool visited[100005];
vector<int> adj[100005];
stack<int> store;
int state[100005];
bool haveCircle = false;
int m, n;
void dfsDAG(int u)
{
    if (haveCircle)
        return;
    state[u] = 1;
    for (int v : adj[u])
    {

        if (state[v] == 0)
        {
            dfsDAG(v);
        }
        if (state[v] == 1)
        {
            haveCircle = true;
            return;
        }
    }
    state[u] = 2;
}
void dfsTopo(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == false)
        {
            dfsTopo(v);
        }
    }
    store.push(u);
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
    // kiểm tra có phải DAG
    for (int i = 1; i <= n; i++)
        if (state[i] == 0)
            dfsDAG(i);
    if (haveCircle)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    // topo sort
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfsTopo(i);
    // in ra
    while (!store.empty())
    {
        cout << store.top() << ' ';
        store.pop();
    }
    return 0;
}

// muốn là topo thì phải kiểm tra xem đồ thị có là DAG hay không
/*
DAG: trace, state
trace[u]=v
state: 0,1,2;
n=5 m=3
1 2
3 1
4 5
*/