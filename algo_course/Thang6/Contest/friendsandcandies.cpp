#include <iostream> 
int numTest; 
int a[200005]; 
int n; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i]; 
    }
    if (sum % n != 0) {
      std::cout << -1 << std::endl; 
    }
    else {
      int ans = 0; 
      for (int i = 1; i <= n; i++) {
        if (a[i] > sum / n) {
          ans++; 
        }
      }
      std::cout << ans << std::endl; 
    }
  }
  return 0; 
}