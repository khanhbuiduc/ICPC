#include <iostream>
#include <string>
#include <math.h>
int numTest; 
std::string X, Y; 
int f[5005][5005]; 

int main () {
  std::cin >> X >> Y;
  int n = (int) X.size();
  int m = (int) Y.size();
  for (int i = 0; i <= n; i++) {
    f[i][0] = i; 
  } 
  for (int j = 0; j <= m; j++) {
    f[0][j] = j; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (X[i - 1] == Y[j - 1]) {
        f[i][j] = f[i - 1][j - 1]; 
      }
      else {
        f[i][j] = std::min(f[i - 1][j], std::min(f[i][j - 1], f[i - 1][j - 1])) + 1; 
      }
    }
  }
  std::cout << f[n][m] << std::endl;
  return 0; 
}