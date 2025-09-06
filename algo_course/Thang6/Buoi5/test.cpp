#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
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
const int MAXN = 2005, INF = 100'000'005;
int n, m, q;
int dist[MAXN], r_dist[MAXN][MAXN], min_dist[MAXN][MAXN];
vector<pii> adj[MAXN], r_adj[MAXN];
void dijkstra(int start)
{
    FOR(i, 1, n)
    dist[i] = INF;
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, start);
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
                pq.emplace(dist[v], v);
            }
        }
    }
}
void r_dijkstra(int s)
{
    FOR(i, 1, n)
    r_dist[s][i] = INF;
    r_dist[s][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, s);
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
                pq.emplace(r_dist[s][v], v);
            }
        }
    }
}
void initial()
{
    cin >> n >> m >> q;
    int ui, vi, ti;
    FOR(i, 1, m)
    {
        cin >> ui >> vi >> ti;
        adj[ui].emplace_back(vi, ti);
        r_adj[vi].emplace_back(ui, ti);
    }
    dijkstra(1);
    FOR(s, 1, n)
    r_dijkstra(s);
    // Khởi tạo min_dist
    FOR(s, 1, n)
    FOR(w, 1, 2000)
    {
        min_dist[s][w] = INF;
    }
    // Tính min_dist[s][w]: với mỗi s, w là trọng số cạnh
    FOR(s, 1, n)
    FOR(u, 1, n)
    for (auto [v, w] : adj[u])
    {
        min_dist[s][w - 1] = min(min_dist[s][w - 1], dist[u] + r_dist[s][v]);
    }
    // Tính subfix min cho min_dist: w(u,v) >= w
    FOR(s, 1, n)
    FORD(w, 1999, 0) //
    min_dist[s][w] = min(min_dist[s][w], min_dist[s][w + 1]);
}
void solve()
{
    while (q--)
    {
        int s, t0;
        cin >> s >> t0;
        cout << min(dist[s], min_dist[s][t0] + t0) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    initial();
    solve();
}