#include <iostream>
#include <algorithm>
#include <vector>
int root[100005];
bool mark[100005];
int n, m;

struct edge {
  int u, v;
};
std::vector <edge> listEdge;

void init() {
  for (int i = 1; i <= n; i++) {
    root[i] = i;
  }
}

int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u]));
}

void solve() {
  std::cin >> n >> m;
  init();
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    listEdge.push_back((edge) {u, v});
  }
  int Q;
  std::cin >> Q;
  std::vector <int> listQuery;
  for (int i = 1; i <= Q; i++) {
    int query;
    std::cin >> query;
    mark[query - 1] = true;
    listQuery.push_back(query);
  }
  int cntWeb = n;
  std::vector <int> res;
  for (int i = 0; i < m; i++) {
    if (mark[i] == false) {
      int u = listEdge[i].u;
      int v = listEdge[i].v;
      int rootu = findRoot(u);
      int rootv = findRoot(v);
      if (rootu != rootv) {
        cntWeb--;
        root[rootu] = rootv;
      }
    }
  }
  for (int i = Q - 1; i >= 0; i--) {
    edge e = listEdge[listQuery[i] - 1];
    res.push_back(cntWeb);
    int u = e.u;
    int v = e.v;
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv) {
      cntWeb--;
      root[rootu] = rootv;
    }
  }
  for (int i = Q - 1; i >= 0; i--) {
    std::cout << res[i] << ' ';
  }
}

int main () {
  solve();
  return 0;
}