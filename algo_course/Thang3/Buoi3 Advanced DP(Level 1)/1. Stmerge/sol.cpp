#include <iostream> 
#include <math.h> 
const long long inf = 100000000000007LL; 
long long f[1005][1005][2]; 
int n, m, numTest;
int cost[1005][1005]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cin >> cost[i][j]; 
      }
    }
    f[0][0][0] = inf;
    f[0][0][1] = inf; 
    for (int i = 1; i <= n; i++) {
      f[i][0][0] = 0; 
      f[i][0][1] = inf; 
    }
    for (int j = 1; j <= m; j++) {
      f[0][j][0] = inf;
      f[0][j][1] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j][0] = std::min(f[i - 1][j][0], f[i - 1][j][1] + cost[i][j]); 
        f[i][j][1] = std::min(f[i][j - 1][1], f[i][j - 1][0] + cost[i][j]); 
      }
    }
    std::cout << std::min(f[n][m][0], f[n][m][1]) << std::endl; 
  }
  return 0; 
}