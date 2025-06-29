#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 1005;
const long long MOD = 1000000007;
long long dp[MAX_N][MAX_N];
int a[MAX_N];
int n, k;
int numTest;

long long POW(long long x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long tmp = POW(x, n >> 1);
  (tmp *= tmp) %= MOD;
  if (n & 1) {
    (tmp *= x) %= MOD;
  }
  return tmp;
}

int main () {
  freopen("SPC1.INP", "r", stdin);
  freopen("SPC1.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    int totalChildren = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      totalChildren += a[i];
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (dp[i][j] == 0) {
          continue;
        }
        long long cur = dp[i][j];
        if (j > 0) {
          (dp[i + 1][j] += (cur * j) % MOD) %= MOD;
        }
        (dp[i + 1][j + 1] += (cur * (k - j)) % MOD) %= MOD;
      }
    }
    int ans = 0;
    for (int j = 1; j <= k; j++) {
      long long val = dp[n][j];
      (val *= POW(k - j + 1, totalChildren)) %= MOD;
      (ans += val) %= MOD;
    }
    cout << ans << endl;
  }
  return 0;
}