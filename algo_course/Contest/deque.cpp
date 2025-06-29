#include <iostream>
#include <math.h>
long long a[3005]; 
long long sum[3005];
long long f[3005][3005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    f[i][i] = a[i];
  }
  for (int l = n - 1; l >= 1; l--) {
    for (int r = l + 1; r <= n; r++) {
      f[l][r] = sum[r] - sum[l - 1] - std::min(f[l + 1][r], f[l][r - 1]); 
    }
  }
  long long X = f[1][n];
  long long Y = sum[n] - X; 
  std::cout << X - Y;
  return 0;
}