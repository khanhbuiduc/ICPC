#include <iostream>
#include <math.h>
const long long inf = -1000000000000007LL;
long long f[3005][3005][5]; 
int n, k, numTest;
long long a[3005], b[3005];

void update(long long &a, long long b) {
  a = std::max(a, b); 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        for (int state = 0; state <= 4; state++) {
          f[i][j][state] = inf; 
        }
      }
    }
    f[0][0][0] = 0LL; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        for (int state = 0; state <= 4; state++) {
          if (f[i][j][state] == inf) {
            continue; 
          }
          update(f[i + 1][j][0], f[i][j][state]); 
          if (j + 1 <= k) {
            update(f[i + 1][j + 1][1], f[i][j][state] + b[i + 1] - a[i + 1] + b[i + 1] - a[i + 1]);
            update(f[i + 1][j + 1][2], f[i][j][state] + b[i + 1] - a[i + 1] + a[i + 1] - b[i + 1]);
            update(f[i + 1][j + 1][3], f[i][j][state] + a[i + 1] - b[i + 1] + b[i + 1] - a[i + 1]);
            update(f[i + 1][j + 1][4], f[i][j][state] + a[i + 1] - b[i + 1] + a[i + 1] - b[i + 1]);
            if (state == 1) {
              update(f[i + 1][j + 1][1], f[i][j][state] - b[i] + b[i + 1] + a[i] - a[i + 1]);
            }
            else if (state == 2) {
              update(f[i + 1][j + 1][2], f[i][j][state] - b[i] + b[i + 1] - a[i] + a[i + 1]); 
            }
            else if (state == 3) {
              update(f[i + 1][j + 1][3], f[i][j][state] + b[i] - b[i + 1] + a[i] - a[i + 1]); 
            }
            else if (state == 4) {
              update(f[i + 1][j + 1][4], f[i][j][state] + b[i] - b[i + 1] - a[i] + a[i + 1]); 
            }
          }                                 
        }
      }
    }
    long long ans = inf; 
    for (int state = 0; state <= 4; state++) {
      update(ans, f[n][k][state]); 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}