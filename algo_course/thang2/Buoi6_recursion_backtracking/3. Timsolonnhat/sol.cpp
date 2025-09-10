#include <iostream> 
#include <math.h> 
int a[105]; 
int n; 
int findMax(int n) {
  if (n == 1) {
    return a[n]; 
  }  
  return std::max(findMax(n - 1), a[n]); 
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  std::cout << findMax(n); 
  return 0; 
}