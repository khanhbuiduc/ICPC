#include <iostream>
#include <iomanip> 

double f[3005][3005]; 
double p[3005]; 
int n; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  f[0][0] = 1.0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (f[i][j] != 0.0) {
        f[i + 1][j + 1] += f[i][j] * p[i + 1]; 
        f[i + 1][j] += f[i][j] * (1.0 - p[i + 1]); 
      }
    }
  }
  double res = 0.0; 
  for (int i = (n + 1) / 2; i <= n; i++) {
    res += f[n][i]; 
  }
  std::cout << std::fixed << std::setprecision(10) << res; 
  return 0; 
}