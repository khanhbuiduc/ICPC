#include <iostream>
#include <vector>
#include <queue>
const int inf = 1000000007; 
int dist[105][10005]; 
int k, n, m, numTest;
struct neighbor {
  int to, length, money; 
};
std::vector <neighbor> adj[105];  
struct element {
  int distance, u, money; 
  bool operator < (const element &other) const {
    return distance > other.distance; 
  }
};

int dijkstra() {
  std::priority_queue <element> pq; 
  for (int i = 1; i <= n; i++) {
    for (int money = 0; money <= k; money++) {
      dist[i][money] = inf; 
    }
  }
  dist[1][0] = 0; 
  pq.push((element) {0, 1, 0}); 
  while (pq.empty() == false) {
    element e = pq.top();
    int distance = e.distance;
    int u = e.u;
    if (u == n) {
      return distance;
    }
    int money = e.money; 
    pq.pop();
    if (distance != dist[u][money]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      neighbor neigh = adj[u][i];
      if (money + neigh.money <= k && dist[neigh.to][money + neigh.money] > dist[u][money] + neigh.length) {
        dist[neigh.to][money + neigh.money] = dist[u][money] + neigh.length;
        pq.push((element) {dist[neigh.to][money + neigh.money], neigh.to, money + neigh.money});     
      }
    }
  }
  return -1; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> k >> n >> m;
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
    }
    for (int i = 1; i <= m; i++) {
      int u, v, length, money;
      std::cin >> u >> v >> length >> money; 
      adj[u].push_back((neighbor) {v, length, money}); 
    }
    std::cout << dijkstra() << std::endl; 
  }
  return 0; 
}