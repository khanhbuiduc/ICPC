#include <iostream>
#include <math.h>
int n, W;
int weight[105], value[105];
long long f[105][100005];

void solve() {
  std::cin >> n >> W;
  for (int i = 1; i <= n; i++) {
    std::cin >> weight[i] >> value[i]; 
  }
  for (int i = 0; i <= n; i++) {
    f[i][0] = 0;
  }
  for (int j = 0; j <= W; j++) {
    f[0][j] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      f[i][j] = f[i - 1][j];
      if (weight[i] <= j) {
        f[i][j] = std::max(f[i][j], f[i - 1][j - weight[i]] + value[i]);
      }
    }
  }
  std::cout << f[n][W];
}

int main () {
  solve();
  return 0;
}