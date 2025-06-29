#include <iostream>
#include <vector>
#include <math.h> 
#include <utility>
int n, m;
std::vector <int> adj[100005];
int low[100005], numb[100005];
int timeDfs = 0; 
std::vector <std::pair <int, int> > ans; 
 
void dfs(int u, int father) {
  timeDfs++; 
  numb[u] = timeDfs; 
  low[u] = timeDfs; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (numb[v] == 0) {
      dfs(v, u); 
      if (low[v] == numb[v]) {
        ans.push_back(std::make_pair(u, v));
      }
      low[u] = std::min(low[u], low[v]); 
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
    if (numb[i] == 0) {
      dfs(i, 0); 
    }
  }
  std::cout << (int) ans.size() << std::endl; 
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i].first << ' ' << ans[i].second << std::endl;
  }
  return 0; 
}