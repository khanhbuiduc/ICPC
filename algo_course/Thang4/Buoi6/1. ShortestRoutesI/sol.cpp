#include <iostream> 
#include <math.h>
#include <utility> 
#include <queue>
#include <functional> 
#include <vector> 
const long long inf = 1000000000000007LL; 
long long dist[100005]; 
std::vector <std::pair <int, int> > adj[100005]; 
int n, m; 
std::priority_queue <std::pair <long long, int>, std::vector <std::pair <long long, int> >, std::greater <std::pair <long long, int> > > pq;
 
void dijkstra(int start) {
  for (int i = 1; i <= n; i++) {
    dist[i] = inf; 
  }
  dist[start] = 0LL; 
  pq.push(std::make_pair(0LL, start)); 
  while (pq.empty() == false) {
    std::pair <long long, int> pqTop = pq.top();
    pq.pop();
    int u = pqTop.second; 
    long long distance = pqTop.first; 
    if (dist[u] != distance) {
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
  for (int i = 1; i <= n; i++) {
    std::cout << dist[i] << ' ';
  }
}
 
int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, weight;
    std::cin >> u >> v >> weight; 
    adj[u].push_back(std::make_pair(v, weight)); 
  }
  dijkstra(1); 
  return 0; 
}