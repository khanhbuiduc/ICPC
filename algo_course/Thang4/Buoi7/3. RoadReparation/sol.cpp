#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <tuple> 
int root[100005]; 
int n, m; 
std::vector <std::tuple <int, int, int> > listEdges; 
long long ans = 0LL;
int numbEdges = 0; 
 
int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}
 
int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    root[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, cost;
    std::cin >> u >> v >> cost;
    listEdges.push_back(std::make_tuple(cost, u, v)); 
  }
  std::sort(listEdges.begin(), listEdges.end()); 
  for (int i = 0; i < m; i++) {
    int u = std::get <1> (listEdges[i]);
    int v = std::get <2> (listEdges[i]);
    int rootu = findRoot(u);
    int rootv = findRoot(v); 
    if (rootu != rootv) {
      root[rootu] = rootv; 
      ans += std::get <0> (listEdges[i]); 
      numbEdges++; 
    }
  }
  if (numbEdges < n - 1) {
    std::cout << "IMPOSSIBLE"; 
  }
  else {
    std::cout << ans; 
  }
  return 0; 
}