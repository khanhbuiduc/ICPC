#include <iostream>
#include <math.h> 
const int inf = -10000007; 
int f[405][205][205]; 
int a[205][205]; 
int n, m; 

int value(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) {
    return a[x1][y1]; 
  }
  return a[x1][y1] + a[x2][y2]; 
}

bool check(int x1, int y1, int x2, int y2) {
  if (x1 != x2 || y1 != y2) {
    return true; 
  }
  if (x1 == x2 && x1 == n && y1 == y2 && y2 == m) {
    return true; 
  }
  return false; 
}

int main () {
  std::cin >> n >> m; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j]; 
    }
  }
  int steps = n + m - 2; 
  for (int i = 0; i <= steps; i++) {
    for (int x1 = 1; x1 <= n; x1++) {
      for (int x2 = 1; x2 <= n; x2++) {
        f[i][x1][x2] = inf; 
      }
    }
  }
  f[0][1][1] = 0; 
  for (int i = 0; i < steps; i++) {
    for (int x1 = 1; x1 <= n; x1++) {
      for (int x2 = x1; x2 <= n; x2++) {
        int y1 = i + 2 - x1;
        int y2 = i + 2 - x2;
        if (check(x1, y1 + 1, x2, y2 + 1) == true) {
          f[i + 1][x1][x2] = std::max(f[i + 1][x1][x2], f[i][x1][x2] + value(x1, y1 + 1, x2, y2 + 1));
        }
        if (x1 + 1 <= x2) {
          if (check(x1 + 1, y1, x2, y2 + 1) == true) {
            f[i + 1][x1 + 1][x2] = std::max(f[i + 1][x1 + 1][x2], f[i][x1][x2] + value(x1 + 1, y1, x2, y2 + 1)); 
          }
        }  
        if (x2 + 1 <= n) {
          if (check(x1, y1 + 1, x2 + 1, y2) == true) {
            f[i + 1][x1][x2 + 1] = std::max(f[i + 1][x1][x2 + 1], f[i][x1][x2] + value(x1, y1 + 1, x2 + 1, y2));
          }
          if (check(x1 + 1, y1, x2 + 1, y2) == true) {
            f[i + 1][x1 + 1][x2 + 1] = std::max(f[i + 1][x1 + 1][x2 + 1], f[i][x1][x2] + value(x1 + 1, y1, x2 + 1, y2));
          }   
        }
      }
    }
  }
  std::cout << f[steps][n][n]; 
  return 0; 
}