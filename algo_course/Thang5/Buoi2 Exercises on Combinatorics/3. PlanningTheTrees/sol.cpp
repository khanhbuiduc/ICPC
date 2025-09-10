#include <iostream> 

const long long mod = 1000000007;
long long fact[10000005]; 
long long sum_fact[10000005];
long long sum_sum_fact[10000005]; 
int numTest; 

void init() {
  fact[0] = 1LL;
  for (int i = 1; i <= 10000000; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % mod;   
  }
  sum_fact[0] = 1LL;
  for (int i = 1; i <= 10000000; i++) {
    sum_fact[i] = (sum_fact[i - 1] + fact[i]) % mod; 
  }
  sum_sum_fact[0] = 1LL; 
  for (int i = 1; i <= 10000000; i++) {
    sum_sum_fact[i] = (sum_sum_fact[i - 1] + sum_fact[i]) % mod; 
  }
}

int main () {
  init(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    if (n == 1) {
      std::cout << 0 << std::endl; 
      continue; 
    }
    long long res = fact[n]; 
    res -= (2 * sum_fact[n - 1]) % mod;
    (res += mod) %= mod;
    res = (res + 1) % mod; 
    (res += sum_sum_fact[n - 2]) %= mod; 
    std::cout << res << std::endl;
  }
  return 0; 
}
