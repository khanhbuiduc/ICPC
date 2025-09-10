#include <iostream> 
#include <math.h> 
int f[60005]; 
int t[60005], r[60005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> t[i]; 
  }
  for (int i = 1; i < n; i++) {
    std::cin >> r[i]; 
  }
  f[0] = 0; 
  f[1] = t[1]; 
  for (int i = 2; i <= n; i++) {
    f[i] = std::min(f[i - 1] + t[i], f[i - 2] + r[i - 1]); 
  }
  std::cout << f[n]; 
  return 0; 
}