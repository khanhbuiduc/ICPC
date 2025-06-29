#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 
int a[MAX_N];       
long long ans = 0;
int n, test; 
vector <int> adj[MAX_N];

void dfs(int u, int parent, long long val) {
  ans += val;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == parent) {
      continue; 
    }
    dfs(v, u, val + a[v]); 
  }  
}

int main () {
  freopen("SPC5.INP", "r", stdin);
  freopen("SPC5.OUT", "w", stdout); 
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      adj[i].clear();  
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v; 
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    for (int i = 1; i <= n; i++) {
      ans = 0;
      dfs(i, 0, a[i]);
      ans -= a[i];
      cout << ans << ' ';
    }
    cout << endl; 
  }
  return 0; 
}