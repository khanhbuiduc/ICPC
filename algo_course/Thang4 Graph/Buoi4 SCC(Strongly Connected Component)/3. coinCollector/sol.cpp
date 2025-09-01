#include <iostream> 
#include <stack> 
#include <vector> 
#include <math.h>
int n, m; 
long long coins[100005]; 
std::vector <int> adj[100005]; 
bool deleted[100005]; 
std::stack <int> store; 
int low[100005], numb[100005]; 
int timeDfs = 0; 
int root[100005]; 
std::vector <int> adj_root[100005]; 
bool visited[100005]; 
std::vector <int> topo;
long long f[100005];
int numbRoot = 0;   
long long totalCoins[100005]; 
 
void dfs(int u) {
  timeDfs++; 
  numb[u] = timeDfs;
  low[u] = timeDfs; 
  store.push(u); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (deleted[v] == true) {
      continue;
    }
    if (numb[v] == 0) {
      dfs(v); 
      low[u] = std::min(low[u], low[v]); 
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }
  if (low[u] == numb[u]) {
    numbRoot++; 
    do {
      int v = store.top(); 
      store.pop(); 
      deleted[v] = true; 
      root[v] = numbRoot; 
      totalCoins[numbRoot] += coins[v]; 
      if (v == u) {
        break; 
      }
    }
    while (true);
  }
}
 
void dfs_topo(int u) {
  visited[u] = true; 
  for (int i = 0; i < (int) adj_root[u].size(); i++) {
    int v = adj_root[u][i];
    if (visited[v] == false) {
      dfs_topo(v); 
    }  
  }
  store.push(u); 
}
 
int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> coins[i]; 
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v); 
  }
  for (int u = 1; u <= n; u++) {
    if (numb[u] == 0) {
      dfs(u); 
    }
  }
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i];
      int rootu = root[u];
      int rootv = root[v]; 
      if (rootu != rootv) {
        adj_root[rootu].push_back(rootv); 
      }
    }
  }
  while (store.empty() == false) {
    store.pop(); 
  }
  for (int u = 1; u <= numbRoot; u++) {
    if (visited[u] == false) {
      dfs_topo(u); 
    }            
  }
  while (store.empty() == false) {
    int u = store.top();
    store.pop();
    topo.push_back(u); 
  }
  for (int i = 1; i <= numbRoot; i++) {
    f[i] = -1; 
  }                            
  long long ans = -1;
  for (int i = 0; i < (int) topo.size(); i++) {
    f[topo[i]] = totalCoins[topo[i]];
    ans = std::max(ans, f[topo[i]]); 
  }
  for (int i = 0; i < (int) topo.size(); i++) {
    int u = topo[i];
    for (int j = 0; j < (int) adj_root[u].size(); j++) {
      int v = adj_root[u][j]; 
      f[v] = std::max(f[v], f[u] + totalCoins[v]); 
      ans = std::max(ans, f[v]); 
    }
  } 
  std::cout << ans; 
  return 0; 
}