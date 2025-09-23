#include <iostream> 
int n, numQueries; 
int f[200005][30]; 
int parent[200005]; 
 
int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 29; j++) {
      f[i][j] = -1; 
    }
  }
  for (int i = 1; i <= n; i++) {
    int u; 
    std::cin >> u;
    f[i][0] = u;
  }
  for (int j = 1; j <= 29; j++) {
    for (int i = 1; i <= n; i++) {
      int u = f[i][j - 1]; 
      u = f[u][j - 1]; 
      f[i][j] = u; 
    }
  }
  for (int query = 1; query <= numQueries; query++) {
    int u, k; 
    std::cin >> u >> k;
    for (int j = 29; j >= 0; j--) {
      if (k >= (1 << j)) {
        u = f[u][j];
        k -= (1 << j);  
      }
    }
    std::cout << u << std::endl;
  }
  return 0; 
}