#include <iostream> 
int numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int l, r;
    std::cin >> l >> r;
    int ans = 0;
    while (l > 0 || r > 0) {
      ans += r - l; 
      l /= 10;
      r /= 10; 
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}