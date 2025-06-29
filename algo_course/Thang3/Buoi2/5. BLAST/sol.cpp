#include <iostream>
#include <string>
#include <math.h> 
std::string s1, s2; 
int f[2005][2005]; 
int k; 
int n, m; 

int main () {
  std::cin >> s1 >> s2; 
  std::cin >> k; 
  n = (int) s1.size();
  m = (int) s2.size();
  for (int i = 0; i <= n; i++) {
    f[i][0] = i * k;
  }
  for (int j = 0; j <= m; j++) {
    f[0][j] = j * k; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = std::min(f[i - 1][j] + k, std::min(f[i][j - 1] + k, f[i - 1][j - 1] + std::abs(s1[i - 1] - s2[j - 1]))); 
    }
  }
  std::cout << f[n][m]; 
  return 0; 
}