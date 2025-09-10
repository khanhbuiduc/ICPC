#include <iostream> 
#include <iomanip> 
#include <math.h>
struct programmer {
  double distance;
  double speed; 
};
programmer a[100005]; 
int n; 
double K; 

double f(const double &x) {
  double minValue = a[1].speed * x + a[1].distance;
  double maxValue = a[1].speed * x + a[1].distance;  
  for (int i = 2; i <= n; i++) {
    minValue = std::min(minValue, a[i].speed * x + a[i].distance);
    maxValue = std::max(maxValue, a[i].speed * x + a[i].distance);
  }
  return maxValue - minValue; 
}

int main () {
  std::cin >> n >> K;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].speed >> a[i].distance; 
  }
  double lo = 0.00000;
  double hi = K; 
  for (int step = 1; step <= 100; step++) {
    double u = (2.0 * lo + hi) / 3.0;
    double v = (lo + 2.0 * hi) / 3.0; 
    if (f(u) > f(v)) {
      lo = u; 
    }
    else {
      hi = v; 
    }
  }
  std::cout << std::fixed << std::setprecision(6) << f(lo); 
  return 0; 
}