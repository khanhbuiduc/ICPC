#include <iostream>     
#include <math.h>
#include <vector> 
#include <unordered_map>     
int n, numDays; 
std::vector <int> adj[200005]; 
int numb[200005], low[200005]; 
int timeDfs = 0; 
int bridges = 0;
std::unordered_map <int, bool> mymap[200005]; 

void dfs(int u, int father) {
  numb[u] = low[u] = ++timeDfs; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (numb[v] == 0) {
      dfs(v, u); 
      low[u] = std::min(low[u], low[v]); 
      if (low[v] == numb[v]) {
        if (mymap[u][v] == true) {
          continue; 
        }
        bridges++; 
      }
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n; 
  for (int i = 1; i < n; i++) {
    int u, v; 
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::cin >> numDays; 
  for (int day = 1; day <= numDays; day++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);               
    mymap[u][v] = true;
    mymap[v][u] = true; 
  }
  dfs(1, -1); 
  std::cout << bridges; 
  return 0; 
}