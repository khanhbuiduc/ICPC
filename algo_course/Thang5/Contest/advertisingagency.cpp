#include <iostream>
const int mod = 1000000007; 
int n, k, numTest; 
int a[1005]; 
int cnt[1005]; 
int C[1005][1005]; 

int main () {
  for (int i = 0; i <= 1000; i++) {
    C[i][0] = 1; 
    C[i][i] = 1; 
  } 
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod; 
    }
  }
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      cnt[a[i]]++; 
    }
    for (int i = n; i >= 1; i--) {
      if (k > cnt[i]) {
        k -= cnt[i];
      }
      else {
        std::cout << C[cnt[i]][k] << std::endl;
        break; 
      }
    }
  }
  return 0; 
}