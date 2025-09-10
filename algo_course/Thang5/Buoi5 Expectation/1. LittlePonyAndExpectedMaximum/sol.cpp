#include <iostream>
#include <iomanip>

double fastpow(const double x, int n) {
  if (n == 0) {
    return 1.0; 
  }
  double ret = fastpow(x, n / 2);
  ret = ret * ret; 
  if (n % 2 == 1) {
    ret = ret * x; 
  }
  return ret;
}

int main () {
  int n, m;
  std::cin >> m >> n; 
  double ans = 0.0; 
  for (int x = 1; x <= m; x++) {
    ans += 1.0 * x * (fastpow(1.0 * x / m, n) - fastpow(1.0 * (x - 1) / m, n));   
  }
  std::cout << std::fixed << std::setprecision(12) << ans;
  return 0; 
}