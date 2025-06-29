#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
const long long mod = 1000000007LL; 
int n, numTest; 
int a[105]; 
long long f[105][72]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }  
    std::memset(f, 0LL, sizeof(f));
    f[0][0] = 1LL;
    for (int i = 0; i < n; i++) {
      for (int value = 0; value <= 70; value++) {
        if (f[i][value] == 0) {
          continue; 
        }
        (f[i + 1][value] += f[i][value]) %= mod; 
        if (value == 0) {
          (f[i + 1][a[i + 1]] += f[i][value]) %= mod; 
        }
        else {
          (f[i + 1][std::__gcd(value, a[i + 1])] += f[i][value]) %= mod; 
        }
      }
    }
    long long ans = 0LL;
    for (int value = 1; value <= 70; value++) {
      (ans += (1LL * value * f[n][value]) % mod) %= mod;
    }  
    std::cout << ans << std::endl;
  }
  return 0; 
}