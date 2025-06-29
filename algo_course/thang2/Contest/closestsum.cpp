#include <iostream>
#include <math.h> 
int testCase = 0; 
int n; 
int a[1005]; 

int main () {
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break; 
    }
    testCase++;
    std::cout << "Case " << testCase << ":" << std::endl; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];  
    }
    int numQuery;
    std::cin >> numQuery;
    for (int query = 1; query <= numQuery; query++) {
      int value;
      std::cin >> value; 
      int diff = std::abs(a[1] + a[2] - value);
      int ans = a[1] + a[2];
      for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
          if (diff > std::abs(a[i] + a[j] - value)) {
            diff = std::abs(a[i] + a[j] - value);
            ans = a[i] + a[j];
          }
        }
      }
      std::cout << "Closest sum to " << value << " is " << ans << "." << std::endl; 
    }
  }
  return 0; 
}