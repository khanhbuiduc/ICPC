#include <iostream> 
#include <vector>
#include <algorithm> 
#include <math.h> 
struct edge {
  int u, v, cost; 
  bool operator < (const edge &other) const {
    return cost < other.cost; 
  }
};            
std::vector <edge> listEdge; 
int root[10005]; 
int n, e, m, k, numTest; 
bool isConnected[10005]; 

int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> e >> m >> k;
    for (int i = 1; i <= n; i++) {
      root[i] = i; 
      isConnected[i] = false; 
    }  
    for (int i = 1; i <= k; i++) {
      int computer; 
      std::cin >> computer; 
      isConnected[computer] = true; 
    }
    listEdge.clear(); 
    for (int i = 1; i <= e; i++) {
      int u, v, w; 
      std::cin >> u >> v >> w; 
      listEdge.push_back((edge) {u, v, w}); 
    }
    std::sort(listEdge.begin(), listEdge.end());
    long long ans = 1LL * (n - k) * m;
    for (int i = 0; i < e; i++) {
      int u = listEdge[i].u;
      int v = listEdge[i].v;
      int cost = listEdge[i].cost;
      int rootu = findRoot(u);
      int rootv = findRoot(v);
      if (rootu != rootv) {
        if (isConnected[rootu] == true && isConnected[rootv] == true) {
          continue; 
        }
        root[rootu] = rootv; 
        if (isConnected[rootu] == true || isConnected[rootv] == true) { 
          isConnected[rootv] = true; 
        }
        ans += cost; 
      } 
    }
    std::cout << ans << std::endl;  
  }
  return 0; 
}