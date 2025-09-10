#include <iostream> 
#include <math.h> 
const int inf = 300005; 
int f[1005][1005]; 
int p[1005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  for (int i = 0; i <= n + 3; i++) {
    for (int j = 0; j <= n + 3; j++) {
      f[i][j] = inf; 
    }
  }
  f[0][0] = 0; 
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      f[i][j] = f[i - 1][j + 1]; 
      if (p[i] <= 100) {
        f[i][j] = std::min(f[i][j], f[i - 1][j] + p[i]);     
      }
      else {
        if (j > 0) {
          f[i][j] = std::min(f[i][j], f[i - 1][j - 1] + p[i]); 
        }
      }
    }
  }
  int ans = inf; 
  for (int j = 0; j <= n; j++) {
    ans = std::min(ans, f[n][j]); 
  }
  std::cout << ans; 
  return 0; 
}