#include <iostream> 

long long power(int n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ans = power(n - 1) * 2LL; 
  return ans;
}

int main () {
  int n;
  std::cin >> n;
  std::cout << power(n); 
  return 0; 
}