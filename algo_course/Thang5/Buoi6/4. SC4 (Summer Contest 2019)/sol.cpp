#include <iostream>
#include <math.h> 
int f[105][105][105]; 
int n, m, numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m; 
    f[0][0][0] = 0; 
    for (int i = 1; i <= n; i++) {
      for (int b = i; b >= 0; b--) {
        for (int a = 0; a <= b; a++) {
          if (b == i) {
            f[i][a][b] = f[a][0][0]; 
          }
          else {
            f[i][a][b] = 0; 
            for (int x = 1; x <= std::min(m, i - b); x++) {
              f[i][a][b] = std::max(f[i][a][b], i - f[i][b - a][b + x]); 
            }
          }
        }
      }
    }
    std::cout << f[n][0][0] << std::endl; 
  }
  return 0; 
}
