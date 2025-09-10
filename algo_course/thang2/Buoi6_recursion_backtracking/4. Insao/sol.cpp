#include <iostream>

void print(int n) {
  if (n == 0) {
    return;
  }
  print(n - 1);
  for (int i = 1; i <= n; i++) {
    std::cout << '*';
  }
  std::cout << std::endl;
}

int main () {
  int n;
  std::cin >> n;
  print(n); 
  return 0;
}