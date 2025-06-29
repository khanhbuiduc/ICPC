#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;
int n, k, numQuery, par[MAX_N];
long long dist[MAX_N];
int root[MAX_N];
vector <pair <int, int> > adj[MAX_N];

struct element {
  char c;
  int a, b, w;
};
vector <element> save;
                               
void dfs(int u, int father, long long D) {
  par[u] = father;
  dist[u] = D;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i].first;
    if (v == father) {
      continue;
    }
    dfs(v, u, D + (long long) adj[u][i].second);
  }
}

int findRoot(int u) {
  return root[u] = (root[u] == u ? u : findRoot(root[u]));
}

bool isSameSet(int u, int v) {
  int uu = findRoot(u);
  int vv = findRoot(v);
  return (uu == vv);
}

void unionSet(int u, int v) {
  int uu = findRoot(u);
  int vv = findRoot(v);
  root[uu] = vv;
}

int main() {
  freopen("SC3.INP", "r", stdin);
  freopen("SC3.OUT", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQuery; 
    save.clear();
    for (int query = 1; query <= numQuery; query++) {
      string oper;  
      cin >> oper;  
      if (oper == "!") {
        int a, b, w;
        cin >> a >> b >> w; 
        save.push_back((element) {oper[0], a, b, w});
      }
      else {
        int a, b;
        cin >> a >> b; 
        save.push_back((element) {oper[0], a, b, 0});
      }
    }
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      adj[i].clear();
    }
    for (int i = 0; i < numQuery; i++) {
      element e = save[i];
      if (e.c == '!') {
        int u = e.a;
        int v = e.b;
        if (isSameSet(u, v) == false) {
          adj[u].push_back(make_pair(v, e.w));
          adj[v].push_back(make_pair(u, -e.w));
          unionSet(u, v);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      root[i] = i;
      par[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      if (par[i] == -1) {
        dfs(i, -1, 0);
      }
    }
    for (int i = 0; i < numQuery; i++) {
      element e = save[i];
      int u = e.a;
      int v = e.b;
      char c = e.c;
      if (c == '?') {
        if (isSameSet(u, v) == false) {
          cout << "UNKNOWN" << endl; 
        }
        else {
          cout << dist[v] - dist[u] << endl; 
        }
      }
      else {
        unionSet(u, v);
      }
    }
  }
  return 0;
}