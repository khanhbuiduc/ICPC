#include <stdio.h>
#include <vector>
#include <fstream> 
struct edge {
  int u, v, cost, change; 
};
int numTest; 
int root[100005];
int n, m, numQueries;  
std::vector <edge> listEdges; 

int findRoot(int u) {
  return (root[u] = (u == root[u] ? u : findRoot(root[u]))); 
}

int main () {
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    scanf("%d %d %d", &n, &m, &numQueries); 
    listEdges.clear(); 
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);  
      listEdges.push_back((edge) {u, v, w, 0}); 
    }
    for (int query = 1; query <= numQueries; query++) {
      int id;
      int cnt;
      scanf("%d %d", &id, &cnt);
      id--; 
      std::vector <int> save; 
      for (int i = 1; i <= cnt; i++) {
        int pos, value; 
        scanf("%d %d", &pos, &value); 
        pos--; 
        listEdges[pos].change = value; 
        save.push_back(pos);  
      }
      for (int i = 1; i <= n; i++) {
        root[i] = i; 
      }
      int cost = (listEdges[id].change == 0 ? listEdges[id].cost : listEdges[id].change); 
      for (int i = 0; i < m; i++) {
        int u = listEdges[i].u;
        int v = listEdges[i].v;
        int weight = (listEdges[i].change == 0 ? listEdges[i].cost : listEdges[i].change);
        if (weight < cost) {
          int rootu = findRoot(u);
          int rootv = findRoot(v);
          if (rootu != rootv) {
            root[rootu] = rootv; 
          }  
        }
      }
      int u = listEdges[id].u;
      int v = listEdges[id].v;
      int rootu = findRoot(u);
      int rootv = findRoot(v);
      if (rootu == rootv) {
        printf("YES\n");
      }
      else {
        printf("NO\n");
      }
      for (int i = 0; i < (int) save.size(); i++) {
        listEdges[save[i]].change = 0;
      } 
    }
  }
  return 0; 
}