#include <iostream> 
#include <fstream>
#include <climits>
int a[30005];
int f[30005];
int n; 
int ans = 0;

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  a[0] = INT_MIN;
  for (int i = 1; i <= n; i++) {
    f[i] = -1; 
  }
  f[0] = 0; 
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[f[ans]]) {
      ans++;
      f[ans] = i;
    }
    else {
      int l = 1; 
      int r = ans; 
      int len = -1; 
      while (l <= r) {
        int mid = (l + r) / 2; 
        if (a[f[mid - 1]] < a[i]) {
          len = mid; 
          l = mid + 1; 
        }
        else {
          r = mid - 1; 
        }
      }
      if (a[f[len]] > a[i]) {
        f[len] = i; 
      }
    }
  }
  std::cout << ans;
  return 0; 
}