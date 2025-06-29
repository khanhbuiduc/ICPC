#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 
int parent[MAX_N]; 
long long up[MAX_N], down[MAX_N]; 
int n, test; 
int a[MAX_N]; 
vector <int> adj[MAX_N]; 
int sz[MAX_N]; 

void dfs1(int u, int parent) {
  sz[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == parent) {
      continue;
    }
    dfs1(v, u); 
    sz[u] += sz[v]; 
  }
}

void dfs2(int u, int parent) {
  down[u] = 1LL * sz[u] * a[u];
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == parent) {
      continue; 
    }
    dfs2(v, u); 
    down[u] += down[v]; 
  }
}

void dfs3(int u, int parent) {
  if (parent != 0) {
    long long val = down[parent]; 
    val -= 1LL * sz[u] * a[parent];
    val -= down[u];
    val += up[parent];
    val += 1LL * (n - sz[u]) * a[u];
    up[u] = val;   
  }
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == parent) {
      continue; 
    }
    dfs3(v, u); 
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
      up[i] = 0;
      down[i] = 0; 
      sz[i] = 0; 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    dfs1(1, 0); 
    dfs2(1, 0);  
    dfs3(1, 0); 
    for (int i = 1; i <= n; i++) {
      cout << up[i] + down[i] - a[i] << ' ';
    }
    cout << endl; 
  }
  return 0; 
}