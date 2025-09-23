#include <iostream>
#include <vector> 
int n, numQuery; 
std::vector <int> adj[200005]; 
int f[200005][20]; 
int parent[200005]; 
int dist[200005]; 
                
void dfs(int u, int father) {
  parent[u] = father; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    dist[v] = dist[u] + 1; 
    dfs(v, u); 
  }
}
 
int main () {
  std::cin >> n >> numQuery; 
  for (int i = 2; i <= n; i++) {
    int father;
    std::cin >> father; 
    adj[i].push_back(father); 
    adj[father].push_back(i); 
  }
  dfs(1, -1); 
  for (int u = 1; u <= n; u++) {
    for (int k = 0; k <= 19; k++) {
      f[u][k] = -1; 
    }
  }
  for (int u = 1; u <= n; u++) {
    f[u][0] = parent[u]; 
  }
  for (int k = 1; k <= 19; k++) {
    for (int u = 1; u <= n; u++) {
      if (f[u][k - 1] != -1) {
        f[u][k] = f[f[u][k - 1]][k - 1]; 
      }
    }
  }
  for (int query = 1; query <= numQuery; query++) {
    int x, k;
    std::cin >> x >> k;
    if (dist[x] < k) {
      std::cout << -1 << std::endl;
      continue; 
    } 
    for (int i = 19; i >= 0; i--) {
      if (k >= (1 << i)) {
        x = f[x][i];
        k -= 1 << i; 
      }
    }
    std::cout << x << std::endl; 
  }
  return 0;
}