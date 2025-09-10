#include <iostream> 
#include <math.h> 
#include <algorithm> 

int f[100005]; 
int h[100005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> h[i]; 
  }
  f[1] = 0; 
  f[2] = std::abs(h[2] - h[1]); 
  for (int i = 3; i <= n; i++) {
    f[i] = std::min(f[i - 1] + std::abs(h[i] - h[i - 1]), f[i - 2] + std::abs(h[i] - h[i - 2])); 
  }
  std::cout << f[n];
  return 0; 
}