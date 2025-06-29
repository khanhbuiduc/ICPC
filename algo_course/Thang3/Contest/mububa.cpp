#include <iostream>
#include <math.h>
int nextPosition[3005][3005]; 
int f[3005][3005]; 
int a[3005]; 
int n; 
long long sum[3005]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      nextPosition[i][j] = -1; 
    }
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    int p = i + 1; 
    for (int j = i; j <= n; j++) {
      p = std::max(j + 1, p); 
      while (p <= n && sum[p] - sum[j] < sum[j] - sum[i - 1]) {
        p++;
      }
      if (p <= n) {
        nextPosition[i][j] = p; 
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = -1; 
    }  
  }
  f[1][1] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      if (f[i][j] == -1) {
        continue; 
      }
      f[i + 1][j] = std::max(f[i + 1][j], f[i][j]);
      int p = nextPosition[f[i][j]][i];
      if (p != -1) {
        f[p][j + 1] = std::max(f[p][j + 1], i + 1); 
      }  
    }
  }
  int ans = -1; 
  for (int j = 1; j <= n; j++) {
    if (f[n][j] != -1) {
      ans = j;
    }
  }
  std::cout << ans; 
  return 0; 
}