#include <iostream> 
const long long mod = 987654321LL; 
long long N; 
bool ok[5]; 

int main () {
  std::cin >> N;
  long long ans = N; 
  if (N % 2 == 0) {
    ans /= 2; 
    ans %= mod; 
    (ans *= (N - 3) % mod) %= mod; 
  }
  else {
    ans %= mod; 
    (ans *= ((N - 3) / 2) % mod) %= mod; 
  }
  (ans += 1) %= mod; 
  long long add = 1LL;
  for (int i = 0; i < 4; i++) {
    long long value = N - i;
    for (int j = 4; j >= 2; j--) {
      if (ok[j] == false && value % j == 0) {
        value /= j;
        ok[j] = true; 
      }
    }  
    value %= mod; 
    (add *= value) %= mod; 
  }                             
  (ans += add) %= mod;
  std::cout << ans; 
  return 0; 
}