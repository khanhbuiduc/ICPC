#include <iostream> 
#include <vector>
#include <math.h>
int n, k; 
std::vector <int> adj[100005]; 
int fw[100005];
long long ans = 0LL;
int parent[100005]; 

void update(int index, const int &value) {
  for (; index <= 100000; index += index & -index) {
    fw[index] += value; 
  }
} 

int get(int index) {
  int ret = 0; 
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

void dfs(int u, int father) {
  int l = std::max(1, u - k);
  int r = std::min(n, u + k); 
  ans += get(r) - get(l - 1);
  update(u, 1); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }  
    dfs(v, u);
  }
  update(u, -1); 
}

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    parent[i] = -1; 
  }
  for (int i = 1; i < n; i++) {
    int father, u;
    std::cin >> father >> u;
    adj[father].push_back(u);
    adj[u].push_back(father);
    parent[u] = father; 
  }
  int root = -1; 
  for (int i = 1; i <= n; i++) {
    if (parent[i] == -1) {
      root = i; 
    }
  }
  dfs(root, -1); 
  std::cout << ans;
  return 0; 
}