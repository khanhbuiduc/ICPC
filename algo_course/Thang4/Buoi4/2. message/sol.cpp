#include <iostream> 
#include <vector> 
#include <stack> 
#include <math.h>
int n, m; 
std::vector <int> adj[805]; 
bool haveIn[805];
int numb[805], low[805];
int root[805]; 
int timeDfs = 0;
bool deleted[805];  
std::stack <int> store; 

void dfs(int u) {
  timeDfs++; 
  numb[u] = low[u] = timeDfs;
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
    do {
      int v = store.top();
      store.pop(); 
      deleted[v] = true; 
      root[v] = u; 
      if (v == u) {
        break; 
      }
    }
    while (true);
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
    if (numb[i] == 0) {
      dfs(i); 
    }
  }
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i]; 
      int rootu = root[u];
      int rootv = root[v]; 
      if (rootu != rootv) {
        haveIn[rootv] = true; 
      }
    }
  } 
  int ans = 0;
  for (int u = 1; u <= n; u++) {
    if (u == root[u] && haveIn[u] == false) {
      ans++; 
    }
  }
  std::cout << ans; 
  return 0;
}              