#include <iostream> 

long long calcpow(long long x, long long n, long long mod) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = calcpow(x, n / 2, mod); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

long long calc(long long x, long long n, long long mod) {
  long long res = 0LL;
  if (n == 0) {
    return 1LL; 
  }
  if (n % 2 == 0) {
    (res += calcpow(x, n, mod)) %= mod;
    (res += calc(x, n - 1, mod)) %= mod; 
  }  
  else {
    long long mul = (1 + calcpow(x, n / 2 + 1, mod)) % mod; 
    (mul *= calc(x, n / 2, mod)) %= mod;
    res = mul;  
  }
  return res; 
}

int main () {
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long x, n, M;
    std::cin >> x >> n >> M;
    std::cout << calc(x, n, M) << std::endl; 
  }
  return 0; 
}