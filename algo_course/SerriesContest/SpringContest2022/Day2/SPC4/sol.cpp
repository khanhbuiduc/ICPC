#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 105; 
const int inf = 1000005; 
int numTest; 
int n; 
int dp[MAX_N][MAX_N * MAX_N]; 
int b[MAX_N], d[MAX_N]; 

int main () {
  freopen("SPC4.INP", "r", stdin); 
  freopen("SPC4.OUT", "w", stdout); 
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    int total = 0; 
    for (int i = 1; i <= n; i++) {
      cin >> b[i]; 
      total += b[i]; 
    }
    for (int i = 1; i <= n; i++) {
      cin >> d[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= total; j++) {
        dp[i][j] = inf; 
      }
    }
    dp[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= total; j++) {
        if (dp[i][j] != inf) {
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + d[i + 1]); 
          dp[i + 1][j + b[i + 1]] = min(dp[i + 1][j + b[i + 1]], dp[i][j]); 
        }
      }
    }
    int res = inf;
    for (int sumb = 0; sumb <= total; sumb++) {
      res = min(res, max(sumb, dp[n][sumb])); 
    }
    cout << res << endl; 
  }
  return 0; 
}