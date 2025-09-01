#include <iostream> 
#include <vector>
#include <math.h>  
int n, m; 
std::vector <int> adj[100005]; 
int low[100005], numb[100005]; 
bool check[100005]; 
bool visited[100005]; 
int timeDFS = 0, bridge = 0; 
std::vector <int> ans; 
 
void dfs(int u, int father) {
  int child = 0; 
  low[u] = numb[u] = ++timeDFS; 
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    if (visited[v] == false) {
      dfs(v, u);         
      low[u] = std::min(low[u], low[v]); 
      if (low[v] == numb[v]) {
        bridge++; 
      }
      child++; 
      if (father == -1) {
        if (child > 1) {
          check[u] = true; 
        }
      }
      else if (low[v] >= numb[u]) {
        check[u] = true; 
      }
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }
}
 
int main () {
  std::cin >> n >> m; 
  for (int i = 1; i <= m; i++) {
    int u, v; 
    std::cin >> u >> v; 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs(i, -1); 
    }
  }
  for (int i = 1; i <= n; i++) {
    if (check[i] == true) {
      ans.push_back(i);  
    }
  }
  std::cout << (int) ans.size() << std::endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << ' ';
  } 
  return 0; 
}