#include <iostream> 
#include <stack>
#include <vector>
int state[100005]; 
std::vector <int> adj[100005]; 
int n, m; 
bool visited[100005]; 
bool haveCycle = false; 
std::stack <int> store; 

void dfs(int u) {
  if (haveCycle == true) {
    return; 
  }
  state[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (state[v] == 1) {
      haveCycle = true; 
      return; 
    }
    if (state[v] == 0) {
      dfs(v); 
    }
  }
  state[u] = 2; 
}
 
void topoSort(int u) {
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      topoSort(v); 
    }
  }
  store.push(u); 
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
  if (haveCycle == true) {
    std::cout << "IMPOSSIBLE";
    return 0; 
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      topoSort(i);   
    }
  }
  while (store.empty() == false) {
    std::cout << store.top() << ' '; 
    store.pop(); 
  }
  return 0; 
}