#include <bits/stdc++.h>
 
using namespace std; 
const int MAX_N = 100005; 
const int MAX_M = 55; 
int n, m, k, d, g1, g2, g3, test; 
string s; 
int dp[MAX_N][MAX_M]; 
 
void updateMax(int &a, int b) {
  a = max(a, b); 
}
 
int main () {
  freopen("AC6.INP", "r", stdin);
  freopen("AC6.OUT", "w", stdout);
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> m >> k >> d >> g1 >> g2 >> g3; 
    cin >> s;
    assert(n == (int) s.size());   
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '#') {
        cnt++; 
      }
    } 
    assert(cnt == m); 
    assert(1 <= n && n <= 100000);
    assert(0 <= m && m <= 50); 
    assert(0 <= d && d <= 100);
    assert(0 <= k && k <= 100);
    assert(0 <= g1 && g1 <= 100);
    assert(0 <= g2 && g2 <= 100);
    assert(0 <= g3 && g3 <= 100); 
    s = "," + s;
    for (int i = 0; i < MAX_N; i++) {
      for (int j = 0; j < MAX_M; j++) {
        dp[i][j] = -1; 
      }
    }
    dp[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
        if (dp[i][j] == -1) {
          continue; 
        }
        int cur = dp[i][j]; 
        updateMax(dp[i + 1][j], cur);
        if (i + 2 <= n && s[i + 1] == '.' && s[i + 2] == '.') {
          updateMax(dp[i + 2][j], cur + 1); 
        }
        if (i + 3 <= n && j < m && s[i + 1] == '.' && s[i + 2] == '#' && s[i + 3] == '.') {
          updateMax(dp[i + 3][j + 1], cur); 
        } 
      }
    }
    int res = -MAX_M * MAX_N; 
    for (int j = 0; j <= m; j++) {
      if (dp[n][j] == -1) {
        break; 
      }
      int numType2 = dp[n][j];
      for (int rep = 0; rep <= numType2; rep++) {
        int rem = numType2 - rep; 
        int val = j * g3 - (m - j) * d; 
        val += rem * g2; 
        int numType1 = n - m - j * 2 - rem * 2; 
        val += min(k, numType1) * g1;
        res = max(res, val); 
      }                                                           
    }
    cout << res << endl;                 
  }
  return 0; 
}