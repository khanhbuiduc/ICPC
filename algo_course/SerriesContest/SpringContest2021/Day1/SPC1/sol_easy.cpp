#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 1005;
const long long MOD = 1000000007;
long long C[MAX_N][MAX_N];
int n, k;
int numTest;
int a[MAX_N];

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
  freopen("output.txt", "w", stdout);
  for (int i = 0; i < MAX_N; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
  }
  for (int i = 1; i < MAX_N; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    int totalChildren = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      totalChildren += a[i];
    }
    long long ans = 0LL;
    for (int numMother = 0; numMother <= n; numMother++) {
      long long val = C[n][numMother];
      if (numMother == 0 || numMother == n) {
        (val *= POW(2, totalChildren)) %= MOD;
      }
      (ans += val) %= MOD;
    }
    cout << ans << endl;
  }
  return 0;
}