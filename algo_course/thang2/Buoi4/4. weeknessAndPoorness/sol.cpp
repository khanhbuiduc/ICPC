#include <iostream> 
#include <math.h>
#include <iomanip>
int n; 
double a[200005]; 

double f(const double &x) {
  for (int i = 1; i <= n; i++) {
    a[i] -= x; 
  }
  double ret = 0.000;
  double minValue = 0.000;
  double maxValue = 0.000;
  double sum = 0.000; 
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    ret = std::max(ret, sum - minValue);
    ret = std::max(ret, maxValue - sum); 
    minValue = std::min(minValue, sum);
    maxValue = std::max(maxValue, sum); 
  }
  minValue = a[n];
  maxValue = a[n]; 
  sum = a[n]; 
  for (int i = n - 1; i >= 1; i--) {
    sum += a[i]; 
    ret = std::max(ret, sum - minValue); 
    ret = std::max(ret, maxValue - sum); 
    minValue = std::min(minValue, sum);
    maxValue = std::max(maxValue, sum); 
  }
  for (int i = 1; i <= n; i++) {
    a[i] += x; 
  }
  return ret; 
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  double lo = -20000.0000;
  double hi = 20000.0000;
  double ans = 0.000000; 
  for (int step = 1; step <= 100; step++) {
    double u = (2.0 * lo + hi) / 3.000; 
    double v = (lo + 2.0 * hi) / 3.000; 
    double fu = f(u);
    double fv = f(v); 
    if (fu >= fv) {
      ans = fu; 
      lo = u; 
    }
    else {
      ans = fv;
      hi = v;  
    }
  }
  std::cout << std::fixed << std::setprecision(12) << ans; 
  return 0; 
}