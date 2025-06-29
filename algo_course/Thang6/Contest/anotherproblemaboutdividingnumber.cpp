#include <iostream> 
#include <math.h> 
#include <algorithm> 
int numTest; 
                  
int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, k;
    std::cin >> a >> b >> k;
    if (k == 1) {
      if (a > b) {
        std::swap(a, b); 
      }
      if (b % a == 0 && b > a) {
        std::cout << "YES"; 
      }
      else {
        std::cout << "NO";
      }
      std::cout << std::endl; 
      continue; 
    } 
    int cnta = 0; 
    for (int p = 2; p * p <= a; p++) {
      while (a % p == 0) {
        cnta++; 
        a /= p; 
      }  
    }
    if (a > 1) {
      cnta++; 
    }
    int cntb = 0; 
    for (int p = 2; p * p <= b; p++) {
      while (b % p == 0) {
        cntb++; 
        b /= p; 
      }  
    }
    if (b > 1) {
      cntb++; 
    }
    std::cout << (cnta + cntb >= k ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}