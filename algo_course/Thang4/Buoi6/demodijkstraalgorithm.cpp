#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
const int inf = 1'000'000'007;
vector<pii> adj[100'005];
int dist[100'005];
#define ff first
#define ss second
priority_queue<pii, vector<pii>, greater<pii>> pq;
int V, E, start;

void initial()
{
  cin >> V >> E >> start;
  for (int i = 1; i <= E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }
  for (int i = 1; i <= V; i++)
    dist[i] = inf;
  dist[start] = 0;
}
void dijkstra()
{
  pq.emplace(0, start);
  while (!pq.empty())
  {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u])
      continue;
    for (auto [v, w] : adj[u])
      if (dist[v] > dist[u] + w)
      {
        dist[v] = dist[u] + w;
        pq.emplace(dist[v], v);
      }
  }
}
int main()
{

  //----
  initial();
  dijkstra();
  for (int i = 1; i <= V; i++)
    cout << dist[i] << " ";
  return 0;
}