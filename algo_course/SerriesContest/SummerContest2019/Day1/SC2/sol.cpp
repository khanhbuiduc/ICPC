#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 3005; 
int dp[MAX_N][MAX_N]; 
int a[MAX_N], b[MAX_N]; 
int n, m, test; 

int main () {
  freopen("SC2.INP", "r", stdin);
  freopen("SC2.OUT", "w", stdout);
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d %d", &n, &m); 
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]); 
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &b[i]); 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        dp[i][j] = 0; 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
        if (a[i] == b[j]) {
          dp[i][j] = max(dp[i][j], dp[max(i - 2, 0)][max(j - 2, 0)] + 1);  
        }
      }
    }
    printf("%d\n", dp[n][m]); 
  }
  return 0; 
}