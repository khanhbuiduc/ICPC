#include <iostream>
#include <iomanip>  
int n, k; 
double a[300005];   
double sum[300005]; 

int main () {
  std::cin >> n >> k; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  double lo = 0.0; 
  double hi = 1000000.00000; 
  for (int step = 1; step <= 500; step++) {
    double mid = (lo + hi) / 2.0; 
    for (int i = 1; i <= n; i++) {
      double value = a[i] - mid;
      sum[i] = sum[i - 1] + value;  
    }
    double mini = 0.0; 
    bool check = false; 
    for (int i = k; i <= n; i++) {
      mini = std::min(mini, sum[i - k]);
      if (sum[i] >= mini) {
        check = true; 
        break; 
      } 
    }
    if (check == false) {
      hi = mid; 
    }
    else {
      lo = mid; 
    }
  }
  std::cout << std::fixed << std::setprecision(6) << lo; 
  return 0; 
}