#include <iostream> 
#include <iomanip>
#include <algorithm> 
#include <functional>
#include <math.h>  
int n; 
double p[105]; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  std::sort(p + 1, p + n + 1, std::greater <double>());
  double mul = 1.0;
  double sum = 0.0;
  double ans = p[1]; 
  for (int i = 1; i <= n; i++) {
    mul *= 1.0 * (1.0 - p[i]); 
    sum += 1.0 * p[i] / (1.0 - p[i]);
    ans = std::max(ans, mul * sum); 
  } 
  std::cout << std::fixed << std::setprecision(12) << ans;
  return 0;
}