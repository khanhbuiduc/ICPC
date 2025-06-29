#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 105; 
int dp[MAX_N][MAX_N][MAX_N]; 
int n, m, test; 

int main () {
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d %d", &n, &m); 
    dp[0][0][0] = 0; 
    for (int i = 1; i <= n; i++) {
      for (int b = i; b >= 0; b--) {
        for (int a = 0; a <= b; a++) {
          if (b == i) {
            dp[i][a][b] = dp[a][0][0]; 
          }
          else {
            dp[i][a][b] = 0; 
            for (int x = 1; x <= min(m, i - b); x++) {
              dp[i][a][b] = max(dp[i][a][b], i - dp[i][b - a][b + x]); 
            }
          }
        }
      }
    }
    printf("%d\n", dp[n][0][0]); 
  }
  return 0; 
}
