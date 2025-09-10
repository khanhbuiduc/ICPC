#include <iostream> 
#include <string> 
const int mod = 1000000007;
std::string s; 
int n;
int sum[3005][3005]; 
int f[3005][3005]; 

int main () {
  std::cin >> n; 
  std::cin >> s;          
  f[1][1] = 1; 
  sum[1][1] = 1; 
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (s[i - 2] == '<') {
        f[i][j] = sum[i - 1][j - 1]; 
      }
      else {
        f[i][j] = sum[i - 1][i - 1];
        f[i][j] -= sum[i - 1][j - 1]; 
        (f[i][j] += mod) %= mod; 
      }
      sum[i][j] = (sum[i][j - 1] + f[i][j]) % mod; 
    }
  }
  int ans = 0; 
  for (int j = 1; j <= n; j++) {
    (ans += f[n][j]) %= mod; 
  }
  std::cout << ans;
  return 0; 
}