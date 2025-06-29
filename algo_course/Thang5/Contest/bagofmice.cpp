#include <iostream> 
#include <iomanip>
double f[1005][1005][2][2];
int numbWhites, numbBlacks; 

int main () {
  std::cin >> numbWhites >> numbBlacks; 
  f[0][0][1][0] = 1.0; 
  for (int i = 0; i <= numbWhites; i++) {
    for (int j = 0; j <= numbBlacks; j++) {
      for (int isPrincess = 0; isPrincess <= 1; isPrincess++) {
        for (int isStopped = 0; isStopped <= 1; isStopped++) {
          if (f[i][j][isPrincess][isStopped] == 0.0) {
            continue; 
          }
          if (isStopped == 1) {
            continue;    
          }
          double prob = f[i][j][isPrincess][isStopped]; 
          double omega = 1.0 * (numbWhites - i + numbBlacks - j);
          if (isPrincess == 0) {
            if (i < numbWhites && j < numbBlacks) {
              f[i + 1][j + 1][1][0] += prob * 1.0 * (numbWhites - i) * (numbBlacks - j) / omega / (omega - 1);
            }
            if (j + 2 <= numbBlacks) {
              f[i][j + 2][1][0] += prob * 1.0 * (numbBlacks - j) * (numbBlacks - j - 1) / omega / (omega - 1);
            }  
          }
          else {
            if (i < numbWhites) {
              f[i + 1][j][0][1] += prob * 1.0 * (numbWhites - i) / omega;  
            }
            if (j < numbBlacks) {
              f[i][j + 1][0][0] += prob * 1.0 * (numbBlacks - j) / omega; 
            }
          }
        }
      }
    }
  }
  double ans = 0.0; 
  for (int i = 0; i <= numbWhites; i++) {
    for (int j = 0; j <= numbBlacks; j++) {
      ans += f[i][j][0][1]; 
    }
  }
  std::cout << std::fixed << std::setprecision(12) << ans; 
  return 0;
}