#include <iostream> 
#include <math.h>
#include <algorithm>
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;
    if (a == b) {
      std::cout << std::min(x, y) / a << std::endl;
      continue;  
    }
    if (a > b) {
      std::swap(a, b); 
    }
    int ans = 0; 
    int lo = 0;
    int hi = std::min(x, y) / a;
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      int v = (x - a * mid) / (b - a);
      int u = (y - a * mid) / (b - a); 
      if (u + v >= mid) {
        ans = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}