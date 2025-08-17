#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
vector<int> adj[100005];
vector<int> adj_group[100005];
int coin[100005];
ll coin_group[100005];
// thành phần liên thông mạnh
int low[100005], num[100005], cntDfs = 0;
bool is_deleted[100005];
stack<int> store;
int root[100005];
int cntgroup = 0;
// topo
bool visited[100005];
vector<int> topo;
// DP
ll f[100005];

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
        cntgroup++;
        while (true)
        {
            int v = store.top();
            store.pop();
            is_deleted[v] = true;
            root[v] = cntgroup;
            coin_group[cntgroup] += coin[v];
            if (v == u)
                break;
        }
    }
}

void dfs_topo(int u)
{
    visited[u] = true;
    for (int v : adj_group[u])
    {
        if (!visited[v])
            dfs_topo(v);
    }
    topo.push_back(u);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Tìm SCC
    for (int i = 1; i <= n; i++)
        if (num[i] == 0)
            dfs(i);

    // Tạo cạnh cho group (loại bỏ trùng lặp)
    set<pair<int, int>> edges;
    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
        {
            if (root[u] != root[v])
                edges.insert({root[u], root[v]});
        }

    for (auto [u, v] : edges)
        adj_group[u].push_back(v);

    // Topo sort cho group
    for (int u = 1; u <= cntgroup; u++)
        if (!visited[u])
            dfs_topo(u);

    reverse(topo.begin(), topo.end());

    // DP - khởi tạo tất cả group
    for (int i = 1; i <= cntgroup; i++)
        f[i] = coin_group[i];

    // DP chính
    for (int u : topo)
    {
        for (int v : adj_group[u])
        {
            f[v] = max(f[v], f[u] + coin_group[v]);
        }
    }

    // Tìm đáp án
    ll maxcoin = 0;
    for (int i = 1; i <= cntgroup; i++)
        maxcoin = max(maxcoin, f[i]);

    cout << maxcoin;
    return 0;
}
/*
Coin Collector
A game has n rooms and m tunnels between them. Each room has a certain number of coins. What is the maximum number of coins you can collect while moving through the tunnels when you can freely choose your starting and ending room?
Input
The first input line has two integers n and m: the number of rooms and tunnels. The rooms are numbered 1,2,\dots,n.
Then, there are n integers k_1,k_2,\ldots,k_n: the number of coins in each room.
Finally, there are m lines describing the tunnels. Each line has two integers a and b: there is a tunnel from room a to room b. Each tunnel is a one-way tunnel.
Output
Print one integer: the maximum number of coins you can collect.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le k_i \le 10^9
1 \le a,b \le n

Example
Input:
4 4
4 5 2 7
1 2
2 1
1 3
2 4

Output:
16
--------------------
cho n phòng, m
thành phần liên thông -> sắp xếp topo tìm đường đi nhiều tiền nhất -> quy hoạch động
*/