#include <iostream>
const int mod = 2111992;
int f[100005];
int n, k; 

int main () {
  std::cin >> n >> k;
  for (int i = 0; i <= k; i++) {
    f[i] = i + 1; 
  }
  for (int i = k + 1; i <= n; i++) {
    f[i] = (f[i - 1] + f[i - k - 1]) % mod;
  }
  std::cout << f[n];
  return 0; 
}
