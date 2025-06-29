#include <bits/stdc++.h> 

using namespace std; 
const long long MOD = 1000000007;
const int MAX_N = 1005; 
long long dp[MAX_N][MAX_N];
int n, test; 

int main () {
  freopen("WC4.INP", "r", stdin);
  freopen("WC4.OUT", "w", stdout);
  cin >> test; 
  for (int t = 1; t <= test; t++) {
    cin >> n; 
    dp[0][0] = 1LL; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i][j] = dp[i - 1][j - 1];
        if (j < i) {
          (dp[i][j] += (1LL * j * dp[i - 1][j]) % MOD) %= MOD; 
        }
      }
    }
    long long res = 0LL;
    for (int i = 1; i <= n; i++) {
      (res += dp[n][i]) %= MOD;
    }
    cout << res << endl; 
  }
  return 0; 
}