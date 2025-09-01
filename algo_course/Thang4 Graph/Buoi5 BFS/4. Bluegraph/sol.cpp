#include <iostream>
#include <queue>
#include <utility>
int n, m, numQuery; 
std::vector <int> adj[500005];
std::priority_queue <std::pair <int, int> > firstQueue; 
std::queue <int> secondQueue; 
int need[500005];
int dist[500005]; 
bool whiteNode[500005]; 

int main () {
  std::vector <int> ans;
  std::cin >> n >> m >> numQuery; 
  for (int i = 1; i <= n; i++) {
    dist[i] = -1; 
    need[i] = -1; 
    whiteNode[i] = false; 
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  for (int i = 1; i <= numQuery; i++) {
    int u; 
    std::cin >> u; 
    whiteNode[u] = true; 
    std::cin >> need[u];
    if (need[u] > 1) {
      firstQueue.push(std::make_pair(need[u] - 1, u)); 
    }
    else if (need[u] == 0) {
      ans.push_back(u); 
    }
  }
  while (!firstQueue.empty()) {
    std::pair <int, int> elementTop = firstQueue.top();
    firstQueue.pop();
    int distance = elementTop.first;
    int u = elementTop.second;
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i];
      if (whiteNode[v] == false) {
        whiteNode[v] = true;
        if (distance > 1) {
          firstQueue.push(std::make_pair(distance - 1, v)); 
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (whiteNode[i] == false) {
      dist[i] = 0; 
      ans.push_back(i); 
    }
  }
  for (int i = 0; i < (int) ans.size(); i++) {
    int u = ans[i];
    dist[u] = 0; 
    secondQueue.push(u);
  }
  while (!secondQueue.empty()) {
    int u = secondQueue.front();
    secondQueue.pop();
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i];
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        secondQueue.push(v); 
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (need[i] != -1 && dist[i] != need[i]) {
      std::cout << "NO";
      return 0; 
    }
  }
  std::cout << "YES" << std::endl;
  std::cout << (int) ans.size() << std::endl; 
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << ' ';
  }
  return 0; 
}