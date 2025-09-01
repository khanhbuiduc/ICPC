#include <iostream>
#include <vector>
std::vector <int> adj[2005];
bool visited[2005]; 
int n, m, cnt = 0; 

void dfs(int u) {
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v); 
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
      cnt++;
      dfs(i); 
    }
  }
  std::cout << m - n + cnt; 
  return 0;
}