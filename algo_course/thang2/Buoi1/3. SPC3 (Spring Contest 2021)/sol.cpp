#include <iostream> 

int a[200005]; 
int n, k, numTest;

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int l = 1; 
    int ans = 0; 
    int numbZero = 0; 
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) {
        numbZero++; 
      }  
      while (numbZero > k) {
        if (a[l] == 0) {
          numbZero--; 
        }
        l++; 
      }
      if (ans < i - l + 1) {
        ans = i - l + 1; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
} 