#include <iostream>
#include <algorithm>
#include <math.h>
const long long inf = 3000000000007LL; 
struct product {
  int a, b, c; 
  bool operator < (const product &other) const {
    return (b - c < other.b - other.c); 
  }
};
product p[3005]; 
long long f_prefix[3005][3005];
long long min_prefix[3005][3005]; 
long long f_suffix[3005][3005];
long long min_suffix[3005][3005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i].a >> p[i].b >> p[i].c;
  }
  std::sort(p + 1, p + n + 1); 
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      f_prefix[i][j] = inf; 
      f_suffix[i][j] = inf; 
    }
  }
  f_prefix[0][0] = 0LL; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      if (f_prefix[i][j] == inf) {
        continue; 
      }
      f_prefix[i + 1][j] = std::min(f_prefix[i + 1][j], f_prefix[i][j] + p[i + 1].a);
      f_prefix[i + 1][j + 1] = std::min(f_prefix[i + 1][j + 1], f_prefix[i][j] + p[i + 1].b - j);  
    }
  }
  for (int i = 0; i <= n; i++) {
    min_prefix[i][0] = f_prefix[i][0]; 
    for (int j = 1; j <= n; j++) {
      min_prefix[i][j] = std::min(min_prefix[i][j - 1], f_prefix[i][j]); 
    }
  }
  f_suffix[n + 1][0] = 0LL;
  for (int i = n + 1; i > 1; i--) {
    for (int j = 0; j <= n; j++) {
      if (f_suffix[i][j] == inf) {
        continue; 
      }
      f_suffix[i - 1][j] = std::min(f_suffix[i - 1][j], f_suffix[i][j] + p[i - 1].a); 
      f_suffix[i - 1][j + 1] = std::min(f_suffix[i - 1][j + 1], f_suffix[i][j] + p[i - 1].c - j); 
    }
  }
  for (int i = n + 1; i >= 1; i--) {
    min_suffix[i][0] = f_suffix[i][0];
    for (int j = 1; j <= n; j++) {
      min_suffix[i][j] = std::min(min_suffix[i][j - 1], f_suffix[i][j]); 
    }
  } 
  long long ans = inf; 
  for (int i = 0; i <= n; i++) {
    ans = std::min(ans, min_prefix[i][i] + min_suffix[i + 1][n - i]);     
  }
  std::cout << ans;
  return 0; 
}