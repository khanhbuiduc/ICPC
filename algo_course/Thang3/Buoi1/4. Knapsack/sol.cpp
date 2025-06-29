#include <iostream>
#include <math.h> 

struct object {
  int weight, value;
};
long long f[105][100005];
object a[105];
int n, W;

int main () {
  std::cin >> n >> W;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].weight >> a[i].value;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      f[i][j] = f[i - 1][j];
      if (a[i].weight <= j) {
        f[i][j] = std::max(f[i][j], f[i - 1][j - a[i].weight] + a[i].value);
      }
    }
  }
  std::cout << f[n][W];
  return 0;
}