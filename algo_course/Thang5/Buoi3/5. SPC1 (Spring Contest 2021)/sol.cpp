#include <iostream>
#include <fstream>

const long long mod = 1000000007;
long long f[1005][1005];
int a[1005];
int n, k;
int numTest;

long long fastpow(long long x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long ret = fastpow(x, n >> 1);
  (ret *= ret) %= mod;
  if (n % 2 == 1) {
    (ret *= x) %= mod;
  }
  return ret;
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    int totalChildren = 0;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      totalChildren += a[i];
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        f[i][j] = 0;
      }
    }
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (f[i][j] == 0) {
          continue;
        }
        long long cur = f[i][j];
        if (j > 0) {
          (f[i + 1][j] += (cur * j) % mod) %= mod;
        }
        (f[i + 1][j + 1] += (cur * (k - j)) % mod) %= mod;
      }
    }
    int ans = 0;
    for (int j = 1; j <= k; j++) {
      long long val = f[n][j];
      (val *= fastpow(k - j + 1, totalChildren)) %= mod;
      (ans += val) %= mod;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}