#include <iostream> 
int n, T; 
int a[100005]; 

int main () {
  std::cin >> n >> T; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  int ans = 0; 
  int l = 1, sum = 0; 
  for (int i = 1; i <= n; i++) {
    sum += a[i]; 
    while (sum > T) {
      sum -= a[l]; 
      l++; 
    }
    if (ans < i - l + 1) {
      ans = i - l + 1; 
    }
  }
  std::cout << ans; 
  return 0; 
}