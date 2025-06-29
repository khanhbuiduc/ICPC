#include <iostream> 
#include <math.h>
const long long inf = -100000000000007LL; 
long long f[100005][32]; 
long long power2[32]; 
int n, k, numTest;
long long a[100005]; 

int main () {
  power2[0] = 1LL; 
  for (int i = 1; i <= 30; i++) {
    power2[i] = power2[i - 1] * 2LL; 
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= 30; j++) {
        f[i][j] = inf; 
      }
    }                  
    f[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 30; j++) {
        if (f[i][j] == inf) {
          continue; 
        }
        f[i + 1][j] = std::max(f[i + 1][j], f[i][j] + a[i + 1] / power2[j] - k);
        if (j < 30) {
          f[i + 1][j + 1] = std::max(f[i + 1][j + 1], f[i][j] + a[i + 1] / power2[j + 1]); 
        } 
      }
    }
    long long ans = inf; 
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= 30; j++) {
        ans = std::max(ans, f[i][j]); 
      }
    }
    std::cout << ans << std::endl;
  }                    
  return 0; 
}