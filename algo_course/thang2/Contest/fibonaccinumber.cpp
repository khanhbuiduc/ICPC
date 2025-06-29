#include <iostream> 
int n; 
long long fibo(int n) {
  if (n == 0) {
    return 0; 
  }
  if (n == 1) {
    return 1; 
  }
  return fibo(n - 1) + fibo(n - 2); 
}

int main () {
  std::cin >> n;
  std::cout << fibo(n); 
  return 0; 
}