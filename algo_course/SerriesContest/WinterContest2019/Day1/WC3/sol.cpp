#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 
vector <int> adj[MAX_N]; 
int n; 
bool mark[MAX_N];
int test; 
int cnt; 

void dfs(int u) {
  mark[u] = true; 
  cnt++;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (mark[v] == false) {
      dfs(v); 
    }
  }
}

int main () {
  freopen("WC3.INP", "r", stdin);
  freopen("WC3.OUT", "w", stdout);
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      mark[i] = false;
    }
    long long res = 1LL * n * (n - 1) / 2;
    for (int i = 1; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      if (w == 0) {
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
    }                  
    for (int i = 1; i <= n; i++) {
      if (mark[i] == false) {
        cnt = 0;
        dfs(i);
        res -= 1LL * cnt * (cnt - 1) / 2; 
      }
    }
    cout << res << endl; 
  }
  return 0; 
}