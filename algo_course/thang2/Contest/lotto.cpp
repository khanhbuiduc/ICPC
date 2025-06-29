#include <iostream>
int lotto[15]; 
int n;

int main () {
  int testCase = 0; 
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break;
    }
    if (testCase == 1) {
      std::cout << std::endl; 
    }
    else {
      testCase = 1; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> lotto[i]; 
    }
    for (int a = 1; a <= n; a++) {
      for (int b = a + 1; b <= n; b++) {
        for (int c = b + 1; c <= n; c++) {
          for (int d = c + 1; d <= n; d++) {
            for (int e = d + 1; e <= n; e++) {
              for (int f = e + 1; f <= n; f++) {
                std::cout << lotto[a] << ' ' << lotto[b] << ' ' << lotto[c] << ' ' << lotto[d] << ' ' << lotto[e] << ' ' << lotto[f] << std::endl;
              }
            }
          }
        }
      }
    }                      
  }
  return 0; 
}