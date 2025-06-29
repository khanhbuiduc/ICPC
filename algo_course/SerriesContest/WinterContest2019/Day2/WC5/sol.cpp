#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 1005; 
const int inf = 1000000007;
int dp[MAX_N][MAX_N][2]; 
int a[MAX_N][MAX_N];
int n, m, test; 

int main () {
  freopen("WC5.INP", "r", stdin);
  freopen("WC5.OUT", "w", stdout);
  scanf("%d", &test);
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d %d", &n, &m); 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        dp[i][j][0] = dp[i][j][1] = inf; 
      }
    }
    for (int i = 1; i <= n; i++) {
      dp[i][0][0] = 0; 
    }         
    for (int j = 1; j <= m; j++) {
      dp[0][j][1] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + a[i][j]);
        dp[i][j][1] = min(dp[i][j - 1][0] + a[i][j], dp[i][j - 1][1]); 
      }
    }
    printf("%d\n", min(dp[n][m][0], dp[n][m][1]));
  }
  return 0; 
}