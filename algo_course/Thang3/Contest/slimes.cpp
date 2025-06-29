#include <iostream>
#include <math.h>
const long long inf = 10000000000000007LL;
int n;
int a[405];
long long f[405][405];
long long cost[405][405];

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      for (int k = i; k <= j; k++) {
        cost[i][j] += a[k];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      f[i][j] = inf;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = i; k < j; k++) {
        f[i][j] = std::min(f[i][j], f[i][k] + f[k + 1][j] + cost[i][j]);
      }
    }
  }
  std::cout << f[1][n];
  return 0;
}