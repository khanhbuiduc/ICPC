#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int MAX_N = 303;
const long long MOD = 1000000007;
string s;
long long dp[MAX_N][MAX_N][MAX_N];
int numTest;

int main () {
  freopen("SPC5.INP", "r", stdin);
  freopen("SPC5.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    int n = (int) s.size();
    for (int i = 0; i <= n; i++) {
      for (int openEye = 0; openEye <= n; openEye++) {
        for (int openSad = 0; openSad <= n; openSad++) {
          dp[i][openEye][openSad] = 0;
        }
      }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int openEye = 0; openEye <= i; openEye++) {
        for (int openSad = 0; openSad <= i; openSad++) {
          if (dp[i][openEye][openSad] == 0) {
            continue;
          }
          long long cur = dp[i][openEye][openSad];
          if (s[i] == 'T') {
            (dp[i + 1][openEye + 1][openSad] += cur) %= MOD;
            if (openSad > 0) {
              (dp[i + 1][openEye][openSad - 1] += (1LL * cur * openSad) % MOD) %= MOD;
            }
          }
          else {
            if (openEye > 0) {
              (dp[i + 1][openEye - 1][openSad + 1] += (1LL * cur * openEye) % MOD) %= MOD;
            }
            if (openSad > 0) {
              (dp[i + 1][openEye][openSad] += (1LL * cur * openSad) % MOD) %= MOD;
            }
          }
        }
      }
    }
    cout << dp[n][0][0] << endl;
  }
  return 0;
}