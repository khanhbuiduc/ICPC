#include <iostream>
#include <math.h>
const long long inf = -10000000007LL; 
long long f[1000005][2]; 
int a[1000005]; 
int n; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 0; i <= n; i++) {
    f[i][0] = f[i][1] = inf; 
  }
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int state = 0; state <= 1; state++) {
      if (f[i][state] == inf) {
        continue;
      }
      f[i + 1][state] = std::max(f[i + 1][state], f[i][state]); 
      f[i + 1][1 - state] = std::max(f[i + 1][1 - state], f[i][state] + 1LL * (state == 0 ? 1 : -1) * a[i + 1]); 
    }
  }
  std::cout << std::max(f[n][0], f[n][1]); 
  return 0;
}