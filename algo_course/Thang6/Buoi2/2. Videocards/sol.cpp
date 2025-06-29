#include <iostream>
#include <math.h>
int n;         
int sum[200005];
int f[200005];  

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    f[x]++; 
  }
  long long ans = -1; 
  for (int i = 1; i <= 200000; i++) {
    sum[i] = sum[i - 1] + f[i]; 
  }
  for (int i = 1; i <= 200000; i++) {
    if (f[i] == 0) {
      continue;   
    }
    long long total = 0LL;  
    for (int j = i; j <= 200000; j += i) {
      total += 1LL * (sum[std::min(200000, j + i - 1)] - sum[j - 1]) * j; 
    }
    ans = std::max(ans, total); 
  }
  std::cout << ans; 
  return 0; 
}