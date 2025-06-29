#include <iostream> 
const long long mod = 1000000007;
long long f[255][255];
int n;
long long k; 
long long powerk[255], powerk1[255]; 
long long C[255][255];

int main () {
  std::cin >> n >> k; 
  powerk[0] = 1;
  powerk1[0] = 1; 
  for (int i = 1; i <= n; i++) {
    powerk[i] = (1LL * powerk[i - 1] * k) % mod; 
    powerk1[i] = (1LL * powerk1[i - 1] * (k - 1)) % mod; 
  }
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    C[i][i] = 1; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod; 
    }
  }
  f[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      if (f[i][j] == 0) {
        continue;
      }
      (f[i + 1][j] += (f[i][j] * (powerk[j] - powerk1[j] + mod) % mod * powerk1[n - j]) % mod) %= mod;
      for (int x = 1; x + j <= n; x++) {
        (f[i + 1][j + x] += (f[i][j] * powerk[j] % mod * powerk1[n - j - x] % mod * C[n - j][x] % mod) % mod) %= mod;     
      } 
    }
  }
  std::cout << f[n][n]; 
  return 0; 
}