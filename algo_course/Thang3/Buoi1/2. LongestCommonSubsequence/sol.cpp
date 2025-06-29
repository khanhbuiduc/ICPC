#include <iostream>
#include <string> 
#include <cstring> 
std::string a, b; 
int f[1005][1005]; 

int main () {
  while (getline(std::cin, a)) {
    getline(std::cin, b);
    std::memset(f, 0, sizeof(f)); 
    int n = (int) a.size(); 
    int m = (int) b.size(); 
    for (int i = 0; i <= n; i++) {
      f[i][0] = 0; 
    }
    for (int j = 0; j <= m; j++) {
      f[0][j] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = std::max(f[i - 1][j], f[i][j - 1]); 
        if (a[i - 1] == b[j - 1]) {
          f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);   
        }
      }
    }
    std::cout << f[n][m] << std::endl; 
  }
  return 0; 
}