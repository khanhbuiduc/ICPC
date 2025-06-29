#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 200005; 
int numTest; 
vector <int> child[MAX_N];
set <int> S[MAX_N]; 
int a[MAX_N]; 
int n;
int ans[MAX_N];  
int step = 0; 

void dfs(int u) {
  S[u].insert(a[u]);
  step++; 
  for (int i = 0; i < (int) child[u].size(); i++) {
    int v = child[u][i];
    dfs(v); 
    if ((int) S[u].size() < (int) S[v].size()) {
      S[u].swap(S[v]); 
    }
    for (set <int> :: iterator it = S[v].begin(); it != S[v].end(); it++) {
      S[u].insert(*it); 
      step++; 
    }                 
    S[v].clear(); 
  }
  ans[u] = (int) S[u].size(); 
}

int main () {
  freopen("SPC3.INP", "r", stdin);
  freopen("SPC3.OUT", "w", stdout); 
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    step = 0; 
    cin >> n; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
      child[i].clear();
      S[i].clear(); 
    }
    int total = 0; 
    for (int i = 1; i <= n; i++) {
      int cnt;
      cin >> cnt;
      total += cnt; 
      for (int j = 1; j <= cnt; j++) {
        int x;
        cin >> x;
        child[i].push_back(x); 
      }
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    } 
    cout << endl; 
  }
  return 0; 
}