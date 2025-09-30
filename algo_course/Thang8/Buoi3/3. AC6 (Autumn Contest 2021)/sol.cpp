#include <iostream>
#include <algorithm>
#include <math.h>
int numTest;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, n;
    std::cin >> a >> b >> n;
    int gcd = std::__gcd(a, b);
    if (n % gcd != 0) {
      std::cout << -1 << std::endl;
      continue;
    }
    a /= gcd;
    b /= gcd;
    n /= gcd;
    if (a > b) {
      std::swap(a, b);
    }             
    bool flag = false;
    for (int i = n / b; i >= 0; i--) {
      int remain = n - i * b;
      if (remain % a == 0) {
        int x = remain / a;
        flag = true;
        std::cout << x + i << std::endl;
        break;
      }
    }
    if (flag == false) {
      std::cout << -1 << std::endl;        
    }
  }
  return 0; 
}










































































        