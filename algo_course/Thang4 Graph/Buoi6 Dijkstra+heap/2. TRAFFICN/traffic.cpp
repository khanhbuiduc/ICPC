#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
const int INF = 1e9 + 7;
const int MAXN = 10'005;

int n, m, k, s, t;
vector<pii> adj[MAXN];
vector<pii> radj[MAXN];
vector<tiii> newBridges;
int dist[MAXN];
int rdist[MAXN];

void dijkstra()
{
    // Khởi tạo khoảng cách
    fill(dist + 1, dist + n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, weight] : adj[u])
        {
            int new_dist = dist[u] + weight;
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }
}
void rdijkstra()
{
    // Khởi tạo khoảng cách
    fill(rdist + 1, rdist + n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    rdist[t] = 0;
    pq.emplace(0, t);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > rdist[u])
            continue;
        for (auto [v, weight] : radj[u])
        {
            int new_dist = rdist[u] + weight;
            if (new_dist < rdist[v])
            {
                rdist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k >> s >> t;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            radj[i].clear();
        }
        newBridges.clear();
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            radj[v].emplace_back(u, w);
        }
        for (int i = 1; i <= k; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            newBridges.emplace_back(u, v, w);
        }
        dijkstra();
        rdijkstra();
        // chiều dài nhỏ nhất là chiều dài s->t hoặc s->t và phải đi qua cầu mới
        int minWidth = dist[t];
        for (auto [u, v, w] : newBridges)
        {
            minWidth = min(minWidth, dist[u] + w + rdist[v]);
            minWidth = min(minWidth, dist[v] + w + rdist[u]);
        }
        cout << (minWidth == INF ? -1 : minWidth) << endl;
    }
    return 0;
}
//