#include <iostream>
#include <string>
#include <math.h>  
int n, m, k, d, g1, g2, g3, numTest; 
std::string s; 
int f[100005][55]; 
 
void updateMax(int &a, int b) {
  a = std::max(a, b); 
}
 
int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k >> d >> g1 >> g2 >> g3; 
    std::cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '#') {
        cnt++; 
      }
    } 
    s = "," + s;
    for (int i = 0; i <= 100000; i++) {
      for (int j = 0; j <= 50; j++) {
        f[i][j] = -1; 
      }
    }
    f[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
        if (f[i][j] == -1) {
          continue; 
        }
        int cur = f[i][j]; 
        updateMax(f[i + 1][j], cur);
        if (i + 2 <= n && s[i + 1] == '.' && s[i + 2] == '.') {
          updateMax(f[i + 2][j], cur + 1); 
        }
        if (i + 3 <= n && j < m && s[i + 1] == '.' && s[i + 2] == '#' && s[i + 3] == '.') {
          updateMax(f[i + 3][j + 1], cur); 
        } 
      }
    }
    int res = -5500005; 
    for (int j = 0; j <= m; j++) {
      if (f[n][j] == -1) {
        break; 
      }
      int numType2 = f[n][j];
      for (int rep = 0; rep <= numType2; rep++) {
        int rem = numType2 - rep; 
        int val = j * g3 - (m - j) * d; 
        val += rem * g2; 
        int numType1 = n - m - j * 2 - rem * 2; 
        val += std::min(k, numType1) * g1;
        res = std::max(res, val); 
      }                                                           
    }
    std::cout << res << std::endl;                 
  }
  return 0; 
}