#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int t, vector<int> &parent, vector<vector<int>> &cap, vector<vector<int>> &adj)
{
    if (u == t)
        return true;
    for (int v : adj[u])
    {
        if (parent[v] == -1 && cap[u][v] > 0)
        {
            parent[v] = u;
            if (dfs(v, t, parent, cap, adj))
                return true;
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>> &cap, int s, int t)
{
    int n = cap.size(), flow = 0;
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            if (cap[u][v])
                adj[u].push_back(v);

    vector<int> parent(n);
    int pathCount = 0;

    while (true)
    {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = s;
        if (!dfs(s, t, parent, cap, adj))
            break;

        // Tìm luồng tăng nhỏ nhất trên đường đi
        int aug = INT_MAX;
        for (int v = t; v != s; v = parent[v])
            aug = min(aug, cap[parent[v]][v]);

        // In ra đường đi
        pathCount++;
        cout << "Duong " << pathCount << ": ";
        vector<int> path;
        for (int v = t; v != s; v = parent[v])
            path.push_back(v);
        path.push_back(s);
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if (i < path.size() - 1)
                cout << " -> ";
        }
        cout << " (luong: " << aug << ")" << endl;

        // Cập nhật luồng
        for (int v = t; v != s; v = parent[v])
        {
            cap[parent[v]][v] -= aug;
            cap[v][parent[v]] += aug;
        }
        flow += aug;
    }
    return flow;
}

int main()
{
    // Ví dụ minh họa:
    // Đồ thị: 0->1 (16), 0->2 (13), 1->2 (10), 2->1 (4), 1->3 (12),
    //         2->4 (14), 3->2 (9), 4->3 (7), 3->5 (20), 4->5 (4)
    vector<vector<int>> cap = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};

    cout << "Cac duong tang luong:" << endl;
    int maxFlow = fordFulkerson(cap, 0, 5);
    cout << "\nMax Flow = " << maxFlow << endl;
}