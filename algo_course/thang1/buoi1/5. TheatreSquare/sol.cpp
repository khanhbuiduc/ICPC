#include <iostream> 

int main () {
  int n, m, a;
  std::cin >> n >> m >> a; 
  long long width = n / a; 
  if (n % a != 0) {
    width++; 
  }
  long long height = m / a;
  if (m % a != 0) {
    height++; 
  }
  std::cout << width * height; 
  return 0; 
}