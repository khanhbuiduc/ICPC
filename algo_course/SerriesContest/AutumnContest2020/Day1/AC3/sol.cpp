#include <bits/stdc++.h> 
using namespace std; 
const int MOD = 1000000007; 
const int MAX_N = 52; 
const int MAX_K = 103;
int dp[2][MAX_N][MAX_N][MAX_K]; 
int a[MAX_N]; 

int main () {
  freopen("AC3.INP", "r", stdin);
  freopen("AC3.OUT", "w", stdout); 
  int test; 
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    int n, G, K; 
    scanf("%d %d %d", &n, &G, &K); 
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]); 
    }
    sort(a + 1, a + n + 1); 
    memset(dp, 0, sizeof(dp)); 
    dp[0][0][0][0] = 1; 
    for (int i = 0; i < n; i++) {
      int cur = i & 1; 
      int next = !cur; 
      memset(dp[next], 0, sizeof(dp[next])); 
      for (int group = 0; group <= min(i, G); group++) {
        for (int open = 0; open <= group; open++) {
          for (int k = 0; k <= K; k++) {
            if (dp[cur][group][open][k] == 0) {
              continue; 
            }
            int val = dp[cur][group][open][k]; 
            if (k + open * (a[i + 1] - a[i]) <= K) {
              int nextVal = k + open * (a[i + 1] - a[i]); 
              (dp[next][group][open][nextVal] += (1LL * open * val) % MOD) %= MOD; 
              (dp[next][group + 1][open][nextVal] += val) %= MOD; 
              if (open > 0) {
                (dp[next][group][open - 1][nextVal] += (1LL * open * val) % MOD) %= MOD; 
              }
              (dp[next][group + 1][open + 1][nextVal] += val) %= MOD; 
            }
          }
        }
      }
    }
    int res = 0; 
    for (int v = 0; v <= K; v++) {
      (res += dp[n & 1][G][0][v]) %= MOD; 
    }
    printf("%d\n", res); 
  }
  return 0; 
}