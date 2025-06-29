#include <iostream>
#include <math.h> 
const int mod = 1000000007; 
int n, k; 
int a[105]; 
int sum[105][100005];
int f[105][100005]; 

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  f[0][0] = 1;
  for (int j = 0; j <= k; j++) {
    sum[0][j] = 1; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      int r = j; 
      int l = std::max(j - a[i], 0);
      f[i][j] = sum[i - 1][r];
      f[i][j] -= sum[i - 1][l];
      (f[i][j] += mod) %= mod;
      (f[i][j] += f[i - 1][l]) %= mod;
      if (j == 0) {
        sum[i][j] = f[i][j]; 
      } 
      else {
        sum[i][j] = (sum[i][j - 1] + f[i][j]) % mod; 
      }
    }
  }
  std::cout << f[n][k]; 
  return 0; 
}