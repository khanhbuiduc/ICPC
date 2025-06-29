#include <iostream> 
#include <math.h> 
int numTest; 
int a[105]; 
int n; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int posMax, posMin;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1) {
        posMin = i; 
      }
      if (a[i] == n) {
        posMax = i; 
      }
    }   
    int ans = std::max(posMin, posMax); 
    ans = std::min(ans, posMin + n - posMax + 1); 
    ans = std::min(ans, posMax + n - posMin + 1); 
    ans = std::min(ans, n - std::min(posMin, posMax) + 1); 
    std::cout << ans << std::endl; 
  }
  return 0; 
}