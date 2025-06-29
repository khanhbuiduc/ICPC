#include <iostream> 
int a[105];
int n, x; 
bool isExist(int n) {
  if (n == 0) {
    return false; 
  }
  if (a[n] == x || isExist(n - 1) == true) {
    return true; 
  }
  return false; 
}

void printPositions(int n) {
  if (n == 0) {
    return; 
  }
  printPositions(n - 1);
  if (x == a[n]) {
    std::cout << n << ' '; 
  }  
}

int main () {
  std::cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (isExist(n) == false) {
    std::cout << "-1"; 
    return 0; 
  } 
  printPositions(n); 
  return 0; 
}