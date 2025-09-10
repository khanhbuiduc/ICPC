#include <iostream> 
#include <math.h>
int n, k; 
int a[200005]; 
int state[200005];
int cnt[200005]; 

int main () {
  std::cin >> n >> k; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  int ans = -1; 
  int lo = 1; 
  int hi = n; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    for (int i = 1; i <= n; i++) {
      if (a[i] >= mid) {
        state[i] = 1; 
      }
      else {
        state[i] = 0; 
      }
    }
    for (int i = 1; i <= n; i++) {
      cnt[i] = cnt[i - 1] + state[i]; 
    }
    bool found = false; 
    int minValue = 2 * cnt[0];    
    for (int i = k; i <= n; i++) {
      if (2 * cnt[i] - i > minValue) {
        found = true;
        break; 
      }
      minValue = std::min(minValue, 2 * cnt[i - k + 1] - (i - k + 1)); 
    }
    if (found == true) {
      ans = mid; 
      lo = mid + 1; 
    }
    else {
      hi = mid - 1; 
    }
  }
  std::cout << ans;
  return 0; 
}