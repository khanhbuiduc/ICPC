#include <iostream> 
#include <math.h> 
const int inf = 1000000007; 
struct item {
  int cost, weight; 
};
item a[105]; 
int n, W;
int f[105][100005];  

int main () {
  std::cin >> n >> W;
  int sum = 0; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].weight >> a[i].cost; 
    sum += a[i].cost; 
  } 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      f[i][j] = inf; 
    }
  } 
  f[0][0] = 0; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (f[i][j] == inf) {
        continue; 
      }
      f[i + 1][j] = std::min(f[i + 1][j], f[i][j]); 
      if (f[i][j] + a[i + 1].weight <= W) {
        f[i + 1][j + a[i + 1].cost] = std::min(f[i + 1][j + a[i + 1].cost], f[i][j] + a[i + 1].weight);
      }
    }
  }
  int ans = inf; 
  for (int j = 0; j <= sum; j++) {
    if (f[n][j] <= W) {
      ans = j; 
    }
  }
  std::cout << ans; 
  return 0; 
}