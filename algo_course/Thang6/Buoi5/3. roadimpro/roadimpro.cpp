#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
using namespace std;
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
typedef pair<int, int> pii;
const int INF = 2e9;
const int MAXN = 2005;
const int MAXW = 2005; // trọng số cạnh ≤ 2000

int n, m, q;
int dist[MAXN];
int r_dist[MAXN][MAXN];
vector<pii> adj[MAXN], r_adj[MAXN];

int min_dist[MAXN][MAXW + 5]; // min_dist[s][t] = min base cho w > t

void dijkstra(int start)
{
    FOR(i, 1, n) { dist[i] = INF; }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void r_dijkstra(int s)
{
    FOR(i, 1, n) { r_dist[s][i] = INF; }
    r_dist[s][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > r_dist[s][u])
            continue;
        for (auto [v, w] : r_adj[u])
        {
            if (r_dist[s][v] > r_dist[s][u] + w)
            {
                r_dist[s][v] = r_dist[s][u] + w;
                pq.push({r_dist[s][v], v});
            }
        }
    }
}
void initial()
{
    cin >> n >> m >> q;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        r_adj[v].push_back({u, w});
    }

    // dist từ 1
    dijkstra(1);

    // r_dist từ mỗi s
    FOR(s, 1, n)
    r_dijkstra(s);

    // khởi tạo min_dist
    FOR(s, 1, n)
    FOR(w, 1, MAXN)
    {
        min_dist[s][w] = INF;
    }
    FOR(s, 1, n)
    FOR(u, 1, n)
    for (auto [v, w] : adj[u])
        minimize(min_dist[s][w - 1], dist[u] + r_dist[s][v]);
    // suffix min cho mọi w(u,v) >= w
    FOR(s, 1, n)
    FORD(w, 2000, 0)
    minimize(min_dist[s][w], min_dist[s][w + 1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    initial();
    while (q--)
    {
        int s, t0;
        cin >> s >> t0;
        cout << min(dist[s], min_dist[s][t0] + t0) << "\n";
    }
}
