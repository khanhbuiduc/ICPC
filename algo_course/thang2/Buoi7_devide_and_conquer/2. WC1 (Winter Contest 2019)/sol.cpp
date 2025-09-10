#include <iostream>
                 
long long prefix[100005], suffix[100005]; 
int n, numTest;
int a[100005]; 
const long long mod = 68718952446LL; 

long long mult(long long a, long long b) {
  if (b == 0) {
    return 0LL;
  }
  long long tmp = mult(a, b / 100000); 
  (tmp *= 1LL * 100000LL) %= mod; 
  if (b % 100000) {
    (tmp += 1LL * (b % 100000) * a) %= mod; 
  }
  return tmp; 
}
                  
int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    prefix[0] = 1LL;
    suffix[n + 1] = 1LL;
    for (int i = 1; i <= n; i++) {
      prefix[i] = (prefix[i - 1] * a[i]) % mod; 
    }
    for (int i = n; i >= 1; i--) {
      suffix[i] = (suffix[i + 1] * a[i]) % mod; 
    }
    for (int i = 1; i <= n; i++) {
      long long ans = prefix[i - 1];
      ans = mult(ans, suffix[i + 1]); 
      std::cout << ans << ' ';
    }
    std::cout << std::endl;
  }
  return 0; 
}