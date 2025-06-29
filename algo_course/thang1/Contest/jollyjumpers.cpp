#include <iostream>
#include <math.h> 
#include <set> 
int a[3005]; 
int n; 

int main () {
  while (std::cin >> n) {
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::set <int> myset; 
    for (int i = 2; i <= n; i++) {
      int diff = std::abs(a[i] - a[i - 1]); 
      if (diff < 1 || diff > n - 1) {
        continue; 
      }
      myset.insert(std::abs(a[i] - a[i - 1]));   
    }
    std::cout << ((int) myset.size() == n - 1 ? "Jolly" : "Not jolly") << std::endl; 
  }
  return 0; 
}