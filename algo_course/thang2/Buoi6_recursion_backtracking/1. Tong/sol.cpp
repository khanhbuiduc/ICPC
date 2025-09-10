#include <iostream> 

int sum(int n) {
  if (n == 0) {
    return 0; 
  }
  int ans = sum(n - 1) + n;
  return ans; 
}

int main () {
  int n; 
  std::cin >> n;
  std::cout << sum(n); 
  return 0; 
}