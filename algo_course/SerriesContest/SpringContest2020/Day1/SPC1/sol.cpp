#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 200005; 
const int MAX_M = 2005; 
const int inf = 1000000007;

int n, m, test; 
int a[MAX_N], b[MAX_M]; 
int dp[MAX_M][MAX_M]; 
vector <int> v[MAX_M]; 

int main () {
  freopen("SPC1.INP", "r", stdin);
  freopen("SPC1.OUT", "w", stdout);
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> m;
    for (int i = 1; i <= 2000; i++) {
      v[i].clear(); 
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      v[a[i]].push_back(i); 
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i]; 
    }
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i][j] = inf; 
      }
    }
    dp[0][0] = 0; 
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= i; j++) {
        if (dp[i][j] == inf) {
          continue; 
        }
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]); 
        int va = b[i + 1]; 
        int l = 0;
        int r = (int) v[va].size() - 1;
        int pos = -1;  
        while (l <= r) {
          int mid = (l + r) >> 1; 
          if (v[va][mid] > dp[i][j]) {
            pos = v[va][mid]; 
            r = mid - 1; 
          }
          else {
            l = mid + 1; 
          }
        }
        if (pos != -1) {
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], pos);
        }
      }
    }
    int res = -1; 
    for (int j = 0; j <= m; j++) {
      if (dp[m][j] != inf) {
        res = j; 
      }
    }
    cout << res << endl; 
  }  
  return 0; 
}