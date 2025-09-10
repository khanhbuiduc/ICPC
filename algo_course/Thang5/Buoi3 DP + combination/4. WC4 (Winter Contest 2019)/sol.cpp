#include <iostream> 
const int mod = 1000000007;
int numTest;
int C[1005][1005]; 
int f[1005]; 
int n; 
void init() {
  for (int i = 0; i <= 1000; i++) {
    C[i][0] = 1;
    C[i][i] = 1; 
  }
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod; 
    }
  }
}

int main () {
  init();
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    f[0] = 1; 
    for (int i = 1; i <= n; i++) {
      f[i] = 0; 
      for (int j = 1; j <= i; j++) {
        (f[i] += (1LL * C[i - 1][j - 1] * f[i - j]) % mod) %= mod;   
      }  
    }
    std::cout << f[n] << std::endl;
  }
  return 0; 
} 