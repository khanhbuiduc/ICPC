#include <iostream> 
#include <bitset>
#include <vector> 
std::vector <int> adj[50005]; 
std::bitset <50005> reachable[50005]; 
int n, m; 
bool visited[50005]; 
 
void dfs(int u) {
  visited[u] = true;
  reachable[u].set(u, 1);  
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (visited[v] == false) {
      dfs(v); 
    }
    reachable[u] |= reachable[v]; 
  }
}
 
int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v); 
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs(i); 
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << reachable[i].count() << ' ';
  }
  return 0; 
}