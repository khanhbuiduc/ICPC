#include <bits/stdc++.h>
using namespace std;

bool haveCircle = false;
void dfs_DAG(int u, vector<int> &state, vector<vector<int>> &adj)
{
    if (haveCircle)
        return;
    state[u] = 1;
    for (int v : adj[u])
    {
        if (state[v] == 0)
        {
            dfs_DAG(v, state, adj);
        }
        if (state[v] == 1)
        {
            haveCircle = true;
            return;
        }
    }
    state[u] = 2;
}
void topo(int u, stack<int> &store, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        topo(v, store, visited, adj);
    }
    store.push(u);
}
void checkDAG(int n, vector<vector<int>> &adj)
{
    vector<int> state(n, 0);
    for (int i = 0; i < n; i++)
        if (state[i] == 0)
            dfs_DAG(i, state, adj);
}
void CreateTopo(int n, stack<int> &store, vector<vector<int>> &adj)
{
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topo(i, store, visited, adj);
    }
}
vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
{
    // nếu item không có group, cho item vào group mới.
    for (int &item : group)
        if (item == -1)
        {
            item = m;
            m++;
        }

    // khởi tạo thứ tự cho group và cây
    vector<vector<int>> adj(n);
    vector<vector<int>> adjGroup(m);
    for (int i = 0; i < n; i++)
    {
        for (int before : beforeItems[i])
        {
            adj[before].push_back(i);
            if (group[before] != group[i])
                adjGroup[group[before]].push_back(group[i]);
        }
    }
    // kiểm tra đồ thị có phải DAG.
    checkDAG(n, adj);
    checkDAG(m, adjGroup);
    if (haveCircle)
        return {};
    // topo sort
    stack<int> store;
    stack<int> storeGroup;

    CreateTopo(n, store, adj);
    CreateTopo(m, storeGroup, adjGroup);
    //
    vector<vector<int>> group_order(m);
    // lưu đúng thứ tự topo trong nhóm
    while (!store.empty())
    {
        int item = store.top();
        store.pop();
        int curGroup = group[item];
        group_order[curGroup].push_back(item);
    }
    // kết quả là xắp xếp lại nhóm theo storeGroup;
    vector<int> ans;
    while (!storeGroup.empty())
    {
        int curGroup = storeGroup.top();
        storeGroup.pop();
        for (int item : group_order[curGroup])
            ans.push_back(item);
    }
    return ans;
}
int main()
{
    int n = 8, m = 2;
    vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};
    vector<int> res = sortItems(n, m, group, beforeItems);
    for (auto i : res)
        cout << i << ' ';
}
