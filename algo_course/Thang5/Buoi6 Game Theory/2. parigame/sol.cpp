#include <iostream>    
int a[505][505]; 
long long sumRow[505][505], sumCol[505][505]; 
int f[505][505];
int n, numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        std::cin >> a[i][j]; 
        f[i][j] = 0;
        sumRow[i][j] = 0;
        sumCol[i][j] = 0; 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        sumRow[i][j] = sumRow[i - 1][j] + a[i][j]; 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        sumCol[i][j] = sumCol[i][j - 1] + a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (sumRow[i][j] % 2 == 0) {
          if (f[i][j - 1] == 0) {
            f[i][j] = 1; 
          }
        }
        if (sumCol[i][j] % 2 == 0) {
          if (f[i - 1][j] == 0) {
            f[i][j] = 1; 
          }
        }
      }
    }
    if (f[n][n] == 1) {
      std::cout << "YES" << std::endl; 
    }
    else {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0;
}