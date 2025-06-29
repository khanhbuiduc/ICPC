#include <iostream> 
#include <stack> 
#include <vector> 
#include <math.h>
int n, m; 
std::vector <int> adj[2005]; 
bool deleted[2005]; 
std::stack <int> store; 
int low[2005], numb[2005]; 
int timeDfs = 0; 
int root[2005]; 
bool visited[2005]; 
int numbRoot = 0;   
bool in[2005], out[2005]; 
std::vector <int> adj_root[2005];
 
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
  if (numbRoot == 1) {
    std::cout << "YES" << std::endl;
    std::cout << "1 2";
    return 0; 
  }
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i];
      int rootu = root[u];
      int rootv = root[v]; 
      if (rootu != rootv) {
        in[rootv] = true;
        out[rootu] = true; 
      }
    }
  }
  int numbIn = 0, numbOut = 0; 
  int firstRoot = -1, lastRoot = -1; 
  for (int i = 1; i <= numbRoot; i++) {
    if (in[i] == false) {
      numbIn++;
      firstRoot = i;
    }
    if (out[i] == false) {
      numbOut++;
      lastRoot = i; 
    }
  }
  if (numbIn != 1 || numbOut != 1) {
    std::cout << "NO"; 
  }
  else {
    int ansFirst = -1, ansLast = -1; 
    for (int i = 1; i <= n; i++) {
      if (root[i] == firstRoot) {
        ansFirst = i;
      }
      if (root[i] == lastRoot) {
        ansLast = i; 
      }
    }
    std::cout << "YES" << std::endl; 
    std::cout << ansLast << ' ' << ansFirst; 
  }
  return 0; 
}