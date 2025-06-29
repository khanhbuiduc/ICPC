#include <iostream>
#include <vector> 
int state[100005];
int trace[100005];  
int n, m;
std::vector <int> adj[100005];
 
void print(int start, int u) {
  std::vector <int> ans; 
  ans.push_back(u); 
  while (start != u) {
    ans.push_back(start); 
    start = trace[start]; 
  }
  std::cout << (int) ans.size() + 1 << std::endl;
  std::cout << u << ' ';
  for (int i = (int) ans.size() - 1; i >= 0; i--) {
    std::cout << ans[i] << ' '; 
  }
}
 
void dfs(int u) {
  state[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (state[v] == 0) {
      trace[v] = u; 
      dfs(v); 
    }
    else if (state[v] == 1) {
      print(u, v);
      exit(0);  
    }
  }
  state[u] = 2; 
} 
 
int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (state[i] == 0) {
      dfs(i); 
    }
  }
  std::cout << "IMPOSSIBLE"; 
  return 0; 
}