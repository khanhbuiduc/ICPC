#include <iostream> 
const long long mod = 1000000007LL; 
int n, m; 

long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

int main () {
  std::cin >> n >> m; 
  long long ans = 1LL; 
  for (int i = 1; i <= n + m - 1; i++) {
    (ans *= (long long) i) %= mod; 
  }
  long long numerator = 1LL; 
  for (int i = 1; i <= n - 1; i++) {
    (numerator *= (long long) i) %= mod; 
  }
  for (int i = 1; i <= m; i++) {
    (numerator *= (long long) i) %= mod; 
  }
  numerator = fastpow(numerator, mod - 2); 
  (ans *= numerator) %= mod; 
  std::cout << ans; 
  return 0; 
}