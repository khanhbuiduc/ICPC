#include <iostream> 
int n;
int a[200005]; 
long long sum[200005]; 
long long x; 

int main () {
  std::cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
    sum[i] = sum[i - 1] + a[i]; 
  }
  int ans = 0; 
  for (int i = 1; i <= n; i++) {
    int lo = 0; 
    int hi = i - 1; 
    bool found = false; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (sum[mid] == sum[i] - x) {
        found = true;
        ans++;
        break; 
      }
      else if (sum[mid] > sum[i] - x) {
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }
  }
  std::cout << ans;
  return 0; 
}