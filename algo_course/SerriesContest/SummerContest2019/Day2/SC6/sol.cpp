#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 2005; 
struct element {
  int l, r; 
};
element a[MAX_N]; 
int n, m, s, e, k, test; 
vector <int> adj[MAX_N]; 
bool mark[MAX_N]; 

void dfs(int u, int key) {
  mark[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (mark[v] == false && a[v].l <= key && key <= a[v].r) {
      dfs(v, key); 
    }
  }
}

int main () {
  freopen("SC6.INP", "r", stdin);
  freopen("SC6.OUT", "w", stdout);
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d %d %d %d %d", &n, &m, &s, &e, &k); 
    vector <int> save; 
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &a[i].l, &a[i].r); 
      save.push_back(a[i].l - 1); 
      save.push_back(a[i].r); 
    }                     
    save.push_back(0); 
    save.push_back(k); 
    sort(save.begin(), save.end());                         
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
    }
    for (int i = 1; i <= m; i++) {
      int u, v; 
      scanf("%d %d", &u, &v); 
      adj[u].push_back(v); 
    }                     
    int res = 0; 
    for (int j = 1; j < (int) save.size(); j++) {
      memset(mark, false, sizeof(mark));
      dfs(s, save[j]); 
      if (mark[e] == true) {
        res += save[j] - save[j - 1]; 
      }
    }
    printf("%d\n", res); 
  }
  return 0; 
}