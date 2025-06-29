#include <iostream>
#include <string>
const long long mod = 1000000007LL;
std::string s;
long long f[305][305][305];
int numTest;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s;
    int n = (int) s.size();
    for (int i = 0; i <= n; i++) {
      for (int openEye = 0; openEye <= n; openEye++) {
        for (int openSad = 0; openSad <= n; openSad++) {
          f[i][openEye][openSad] = 0;
        }
      }
    }
    f[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int openEye = 0; openEye <= i; openEye++) {
        for (int openSad = 0; openSad <= i; openSad++) {
          if (f[i][openEye][openSad] == 0) {
            continue;
          }
          long long cur = f[i][openEye][openSad];
          if (s[i] == 'T') {
            (f[i + 1][openEye + 1][openSad] += cur) %= mod;
            if (openSad > 0) {
              (f[i + 1][openEye][openSad - 1] += (1LL * cur * openSad) % mod) %= mod;
            }
          }
          else {
            if (openEye > 0) {
              (f[i + 1][openEye - 1][openSad + 1] += (1LL * cur * openEye) % mod) %= mod;
            }
            if (openSad > 0) {
              (f[i + 1][openEye][openSad] += (1LL * cur * openSad) % mod) %= mod;
            }
          }
        }
      }
    }
    std::cout << f[n][0][0] << std::endl;
  }
  return 0;
}