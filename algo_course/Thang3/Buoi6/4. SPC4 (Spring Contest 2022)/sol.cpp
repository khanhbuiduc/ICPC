#include <iostream> 
#include <math.h> 
const int inf = 1000005; 
int f[105][10005]; 
int n, numTest; 
int b[105], d[105]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    int totalTime = 0; 
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i];
      totalTime += b[i];
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> d[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= totalTime; j++) {
        f[i][j] = inf; 
      }
    }
    f[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= totalTime; j++) {
        if (f[i][j] == inf) {
          continue; 
        }
        f[i + 1][j + b[i + 1]] = std::min(f[i + 1][j + b[i + 1]], f[i][j]); 
        f[i + 1][j] = std::min(f[i + 1][j], f[i][j] + d[i + 1]); 
      }
    }
    int ans = inf; 
    for (int j = 0; j <= totalTime; j++) {
      if (f[n][j] != inf) {
        ans = std::min(ans, std::max(j, f[n][j])); 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}