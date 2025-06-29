#include <iostream>
#include <string>
#include <math.h>
std::string s; 
int f[5005][5005]; 
int n; 

int main () {
  std::cin >> n; 
  std::cin >> s;
  for (int i = 1; i <= n; i++) {
    f[i][i] = 0; 
  }         
  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      if (s[i - 1] == s[j - 1]) {
        f[i][j] = f[i + 1][j - 1]; 
      }
      else {
        f[i][j] = std::min(f[i + 1][j], f[i][j - 1]) + 1; 
      }
    }
  }
  std::cout << f[1][n];
  return 0; 
}