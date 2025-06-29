#include <iostream> 
#include <math.h> 
int f[1005]; 
int n; 
int a[1005]; 
int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  a[0] = 0; 
  f[0] = 0; 
  int ans = 0; 
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        f[i] = std::max(f[i], f[j] + 1); 
      }
    }
    ans = std::max(ans, f[i]); 
  }
  std::cout << ans; 
  return 0; 
}