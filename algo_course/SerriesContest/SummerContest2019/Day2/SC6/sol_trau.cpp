#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 2005; 
struct element {
  int l, r; 
};
element a[MAX_N]; 
int n, m, s, e, K, test; 
vector <int> adj[MAX_N]; 
bool mark[MAX_N];
bool check; 

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
  freopen("output.txt", "w", stdout);
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d %d %d %d %d", &n, &m, &s, &e, &K); 
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &a[i].l, &a[i].r); 
    }
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
    }
    for (int i = 1; i <= m; i++) {
      int u, v; 
      scanf("%d %d", &u, &v); 
      adj[u].push_back(v); 
    }
    int res = 0; 
    for (int x = 1; x <= K; x++) {
      for (int i = 1; i <= n; i++) {
        mark[i] = false; 
      }   
      dfs(s, x); 
      if (mark[e] == true) {
        res++; 
      }
    }
    printf("%d\n", res); 
  }
  return 0; 
}