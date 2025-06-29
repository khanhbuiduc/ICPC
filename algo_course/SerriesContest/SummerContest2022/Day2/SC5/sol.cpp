#include <bits/stdc++.h> 

using namespace std; 
const int MOD = 1000000007; 
int dp[2][(1 << 10) + 5][22][22];
int n, m, c, k; 
int numTest; 

int main () {
  freopen("SC5.INP", "r", stdin);
  freopen("SC5.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m >> c >> k;
    if (n > m) {
      swap(n, m); 
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1; 
    for (int i = 0; i < n * m; i++) {
      int cur = i & 1; 
      int nxt = !cur; 
      memset(dp[nxt], 0, sizeof(dp[nxt])); 
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int numCows = 0; numCows <= c; numCows++) {
          for (int numLims = 0; numLims <= k; numLims++) {
            if (dp[cur][mask][numCows][numLims] == 0) {
              continue; 
            }
            int nextmask = mask / 2; 
            (dp[nxt][nextmask][numCows][numLims] += dp[cur][mask][numCows][numLims]) %= MOD; 
            if (numCows < c) {
              int cntAdj = numLims; 
              if ((mask & 1) > 0) {
                cntAdj++; 
              }
              if (i % n != 0 && ((mask & (1 << (n - 1))) > 0)) {
                cntAdj++; 
              }
              if (cntAdj <= k) {
                (dp[nxt][nextmask + (1 << (n - 1))][numCows + 1][cntAdj] += dp[cur][mask][numCows][numLims]) %= MOD; 
              }
            }
          }
        }
      }
    }
    int ans = 0; 
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int numLims = 0; numLims <= k; numLims++) {
        (ans += dp[(n * m) & 1][mask][c][numLims]) %= MOD; 
      }
    }
    cout << ans << endl; 
  }                    
  return 0; 
}