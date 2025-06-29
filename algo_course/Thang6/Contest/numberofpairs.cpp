#include <iostream> 
#include <math.h> 
#include <algorithm> 
int numTest; 
const int inf = -1000000007; 
int n, l, r; 
int a[200005]; 

int findPosition(int X) {
  int lo = 0; 
  int hi = n; 
  int ret = -1; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] <= X) {
      ret = mid; 
      lo = mid + 1; 
    }  
    else {
      hi = mid - 1; 
    }
  }
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> l >> r; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    a[0] = inf; 
    std::sort(a + 1, a + n + 1);
    long long ans = 0LL;  
    for (int i = 2; i <= n; i++) {
      int L = l - a[i]; 
      int R = r - a[i]; 
      int maxPos = findPosition(R); 
      int minPos = findPosition(L - 1); 
      maxPos = std::min(maxPos, i - 1); 
      minPos++;  
      if (minPos <= maxPos) {
        ans += maxPos - minPos + 1;
      } 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}