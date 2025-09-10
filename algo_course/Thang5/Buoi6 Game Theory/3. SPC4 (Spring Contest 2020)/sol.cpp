#include <iostream>
#include <math.h> 
int numTest, n, K, T; 
int a[32], sum[32];
int f[32][32][32]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> K >> T;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];  
    }
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int cur = 0; cur < 32; cur++) {
        for (int op = 0; op < 32; op++) {
          f[i][cur][op] = 0; 
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int cur = 0; cur < 32; cur++) {
        for (int op = 0; op < 32; op++) {
          for (int x = 0; x <= cur && x <= i - 1; x++) {
            f[i][cur][op] = std::max(f[i][cur][op], sum[i] - f[i - 1 - x][op][cur - x]); 
          }
        }
      }   
    }
    int first = f[n][K][T]; 
    int second = sum[n] - first;
    if (first < second) {
      std::cout << "LOSE";
    }
    else if (first > second) {
      std::cout << "WIN";
    }
    else {
      std::cout << "DRAW"; 
    }
    std::cout << std::endl;
  } 
  return 0; 
}