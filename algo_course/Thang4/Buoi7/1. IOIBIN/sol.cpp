#include <iostream> 
int root[10005]; 

int findRoot(int u) {
  return (root[u] = (root[u] == u ? u : findRoot(root[u])));
}

void unionSet(int u, int v) {
  int rootu = findRoot(u);
  int rootv = findRoot(v); 
  if (rootu != rootv) {
    root[rootu] = rootv;
  }
}

int main () {
  for (int i = 1; i <= 10000; i++) {
    root[i] = i;
  }
  int numQuery;
  std::cin >> numQuery;
  for (int i = 1; i <= numQuery; i++) {
    int u, v, type;
    std::cin >> u >> v >> type; 
    if (type == 1) {
      unionSet(u, v); 
    }
    else {
      int rootu = findRoot(u);
      int rootv = findRoot(v);
      std::cout << (rootu == rootv) << std::endl;
    }
  }
  return 0; 
}