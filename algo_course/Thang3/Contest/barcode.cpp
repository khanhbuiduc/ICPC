#include <iostream>
#include <math.h>
#include <string>
const int inf = 1000007; 
int f[1005][2];
int sum[1005]; 
int n, m, x, y;
std::string a[1005];

int main () {
  std::cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    int value = 0;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == '#') {
        value++;
      }
    }
    sum[j + 1] = sum[j] + value;
  }
  for (int i = 0; i <= m; i++) {
    f[i][0] = f[i][1] = inf; 
  }
  f[0][0] = 0;
  f[0][1] = 0;
  for (int i = 0; i <= m; i++) {
    if (f[i][0] != inf) {
      for (int j = x; j <= y; j++) {
        if (i + j <= m) {
          f[i + j][1] = std::min(f[i + j][1], f[i][0] + sum[i + j] - sum[i]); 
        }
      }
    }
    if (f[i][1] != inf) {
      for (int j = x; j <= y; j++) {
        if (i + j <= m) {
          f[i + j][0] = std::min(f[i + j][0], f[i][1] + j * n - (sum[i + j] - sum[i])); 
        }
      }
    }
  }
  std::cout << std::min(f[m][0], f[m][1]); 
  return 0; 
}