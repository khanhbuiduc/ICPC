#include <iostream>
#include <iomanip>
double dp[305][305][305]; 
double prob[305][305][305];
int n; 
int cnt[4]; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    int x;          
    std::cin >> x; 
    cnt[x]++;
  }
  prob[cnt[1]][cnt[2]][cnt[3]] = 1.0;  
  for (int c3 = 300; c3 >= 0; c3--) {
    for (int c2 = 300; c2 >= 0; c2--) {
      for (int c1 = 300; c1 >= 0; c1--) {
        if (prob[c1][c2][c3] > 0.0) {
          double E = dp[c1][c2][c3];
          double p = prob[c1][c2][c3];
          double S = c1 + c2 + c3; 
          p *= n;
          p *= 1.0 / (S * S); 
          if (c1 > 0) {
            prob[c1 - 1][c2][c3] += prob[c1][c2][c3] * c1 / S;
            dp[c1 - 1][c2][c3] += E * c1 * 1.0 / S + 1.0 * c1 * p;
          }
          if (c2 > 0) {
            prob[c1 + 1][c2 - 1][c3] += prob[c1][c2][c3] * c2 / S;
            dp[c1 + 1][c2 - 1][c3] += E * c2 * 1.0 / S + 1.0 * c2 * p; 
          }
          if (c3 > 0) {
            prob[c1][c2 + 1][c3 - 1] += prob[c1][c2][c3] * c3 / S;
            dp[c1][c2 + 1][c3 - 1] += E * c3 * 1.0 / S + 1.0 * c3 * p; 
          }
        }
      }
    }
  }
  std::cout << std::fixed << std::setprecision(10) << dp[0][0][0];
  return 0; 
}