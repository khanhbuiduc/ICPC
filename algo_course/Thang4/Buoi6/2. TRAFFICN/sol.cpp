#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <math.h>
const int inf = 1000000007; 
int numTest;                 
int n, m, k, startNode, endNode;               
std::vector <std::vector <std::pair <int, int> > > adj, rev_adj;
std::vector <int> dist, rev_dist; 

void dijkstra(const int &startNode, std::vector <std::vector <std::pair <int, int> > > &adj, std::vector <int> &dist) {
  std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >, std::greater <std::pair <int, int> > > pq;
  dist[startNode] = 0;
  pq.push(std::make_pair(0, startNode));
  while (!pq.empty()) {
    std::pair <int, int> elementTop = pq.top();
    pq.pop();
    int u = elementTop.second;
    int distance = elementTop.first;
    if (distance != dist[u]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, int> neighbor = adj[u][i];
      int v = neighbor.first;
      int weight = neighbor.second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(std::make_pair(dist[v], v)); 
      }
    }
  }  
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k >> startNode >> endNode;
    dist.resize(n + 1, inf);
    rev_dist.resize(n + 1, inf);
    adj.clear();
    rev_adj.clear();
    adj.resize(n + 1); 
    rev_adj.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      rev_adj[i].clear();
      dist[i] = inf;
      rev_dist[i] = inf;
    }
    for (int i = 1; i <= m; i++) {
      int u, v, weight;
      std::cin >> u >> v >> weight; 
      adj[u].push_back(std::make_pair(v, weight));
      rev_adj[v].push_back(std::make_pair(u, weight));
    }
    dijkstra(startNode, adj, dist);
    dijkstra(endNode, rev_adj, rev_dist);
    int ans = dist[endNode];
    for (int i = 1; i <= k; i++) {
      int u, v, weight;
      std::cin >> u >> v >> weight;
      if (dist[u] != inf && rev_dist[v] != inf) {
        ans = std::min(ans, dist[u] + rev_dist[v] + weight);
      } 
      if (dist[v] != inf && rev_dist[u] != inf) {
        ans = std::min(ans, dist[v] + rev_dist[u] + weight);
      }
    }
    std::cout << (ans == inf ? -1 : ans) << std::endl; 
  }
  return 0;
}