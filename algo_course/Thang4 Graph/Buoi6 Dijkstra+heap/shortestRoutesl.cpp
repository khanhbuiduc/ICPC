#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = 1e18;
const int MAXN = 100005;

int n, m;
vector<pair<int, int>> adj[MAXN];
ll dist[MAXN];

void dijkstra(int start)
{
    // Khởi tạo khoảng cách
    fill(dist + 1, dist + n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, weight] : adj[u])
        {
            ll new_dist = dist[u] + weight;
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}