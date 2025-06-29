#include <iostream>
#include <math.h>
int a[1505], b[1505];
int n, m, numTest; 
int f[1505]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 1; i <= m; i++) {
      std::cin >> b[i]; 
    }
    for (int i = 1; i <= m; i++) {
      f[i] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      int maxLength = 0; 
      for (int j = 1; j <= m; j++) {
        int prev = maxLength; 
        if (2 * b[j] <= a[i]) {
          maxLength = std::max(maxLength, f[j]);
        }
        if (a[i] == b[j]) {
          f[j] = std::max(f[j], prev + 1); 
        }
      }
    }
    int ans = 0; 
    for (int i = 1; i <= m; i++) {
      ans = std::max(ans, f[i]); 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}
