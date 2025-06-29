#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 2005; 
int a[MAX_N], b[MAX_N];
int n, m; 
int dp[MAX_N][MAX_N]; 
int test; 

int main () {
  freopen("SPC1.inp", "r", stdin);
  freopen("SPC1.out", "w", stdout);
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i];
    }
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
      dp[0][j] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (a[i] == b[j]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);  
        }
      }
    }
    cout << dp[n][m] << endl; 
  } 
  return 0; 
}