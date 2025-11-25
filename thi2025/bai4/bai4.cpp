#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e18;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int n, m;
vector<ll> dist;
vector<vector<pii>> adj;
void dijkstra(int start)
{
    FOR(i, 0, n) { dist[i] = INF; }
    dist[start] = 0;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    dist.resize(n + 5);
    adj.resize(n + 5);
    int S, T;
    cin >> S >> T;
    FOR(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); // 1 chiều
    }
    dijkstra(S);
    if (dist[T] == INF)
        cout << -1;
    else
    {
        cout << dist[T];
    }
}