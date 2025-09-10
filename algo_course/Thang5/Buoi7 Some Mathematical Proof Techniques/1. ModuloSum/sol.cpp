#include <iostream>
int a[1000005];
int f[1005][1005][2];
int n, k;  

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] %= k; 
  }
  if (n > k) {
    std::cout << "YES";
    return 0; 
  }
  f[0][0][0] = 1; 
  for (int i = 0; i < n; i++) {
    for (int r = 0; r < k; r++) {
      for (int state = 0; state <= 1; state++) {
        if (f[i][r][state] == 0) {
          continue; 
        }
        f[i + 1][r][state] = 1;
        f[i + 1][(r + a[i + 1]) % k][1] = 1; 
      }
    }
  }
  std::cout << (f[n][0][1] == 1 ? "YES" : "NO"); 
  return 0; 
}