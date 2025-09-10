#include <iostream> 
#include <algorithm>
int numTest;
int n, C;
int x[100005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> C;
    for (int i = 1; i <= n; i++) {
      std::cin >> x[i];
    }
    std::sort(x + 1, x + n + 1);
    int lo = 1;
    int hi = 1000000000;
    int ans = -1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      int lastPosition = x[1];
      int numbCows = 1;
      for (int i = 2; i <= n; i++) {
        if (x[i] - lastPosition >= mid) {
          numbCows++;
          lastPosition = x[i]; 
        }
      }
      if (numbCows >= C) {
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