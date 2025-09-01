#include <iostream> 
#include <math.h>
#include <vector>
int n, numFlights; 
std::vector <int> adj[105]; 
int sz[105]; 
int numb[105], low[105]; 
int timeDfs = 0, ans = 0; 

void dfs(int u, int father) {
  numb[u] = low[u] = ++timeDfs; 
  sz[u] = 1;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    if (numb[v] == 0) {
      dfs(v, u);
      sz[u] += sz[v];  
      low[u] = std::min(low[u], low[v]); 
      if (numb[v] == low[v]) {
        ans += sz[v] * (n - sz[v]);   
      }
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }
}

int main () {
  std::cin >> n >> numFlights; 
  for (int flight = 1; flight <= numFlights; flight++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1); 
  std::cout << ans; 
  return 0; 
}