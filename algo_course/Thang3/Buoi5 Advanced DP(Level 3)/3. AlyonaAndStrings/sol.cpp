#include <iostream> 
#include <math.h> 
#include <string>       
int f[1005][1005][12][2];  
int n, m, k; 
std::string s, t; 

void update(int &a, int b) {
  a = std::max(a, b); 
}

int main () {
  std::cin >> n >> m >> k; 
  std::cin >> s >> t; 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int numb = 0; numb <= k; numb++) {
        for (int state = 0; state <= 1; state++) {
          f[i][j][numb][state] = -1; 
        }
      }
    }
  }
  f[0][0][0][0] = 0; 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int numb = 0; numb <= k; numb++) {
        for (int state = 0; state <= 1; state++) {
          if (f[i][j][numb][state] == -1) {
            continue; 
          }
          if (i < n && j < m && s[i] == t[j]) {
            update(f[i + 1][j + 1][numb + 1][1], f[i][j][numb][state] + 1); 
            if (state == 1) {
              update(f[i + 1][j + 1][numb][1], f[i][j][numb][state] + 1); 
            }
          }
          if (i < n) {
            update(f[i + 1][j][numb][0], f[i][j][numb][state]); 
          }
          if (j < m) {
            update(f[i][j + 1][numb][0], f[i][j][numb][state]); 
          }
        }
      }
    }
  }
  std::cout << std::max(f[n][m][k][0], f[n][m][k][1]); 
  return 0; 
}