#include <iostream>
#include <fstream> 
#include <vector> 
#include <queue>
#include <utility>
#include <functional>
const int inf = 1000000007; 
int dist[100005];
std::vector <std::pair <int, int> > adj[100005];
std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int> >, std::greater <std::pair <int, int> > > pq;
int V, E, start;  

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> V >> E >> start;
  for (int i = 1; i <= E; i++) {
    int u, v, w; 
    std::cin >> u >> v >> w; 
    adj[u].push_back(std::make_pair(v, w)); 
  }
  for (int i = 1; i <= V; i++) {
    dist[i] = inf; 
  } 
  dist[start] = 0;
  pq.push(std::make_pair(0, start));
  while (!pq.empty()) {
    std::pair <int, int> pqTop = pq.top();
    pq.pop();
    int u = pqTop.second; 
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, int> neighbor = adj[u][i]; 
      int v = neighbor.first;
      int w = neighbor.second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(std::make_pair(dist[v], v)); 
      }
    }
  }
  for (int i = 1; i <= V; i++) {
    std::cout << dist[i] << " "; 
  }
  return 0; 
}