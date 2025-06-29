#include <iostream>
#include <iomanip>
int R, S, P; 
double f[105][105][105]; 

int main () {
  std::cin >> R >> S >> P;
  f[R][S][P] = 1.0;
  for (int r = R; r >= 0; r--) {
    for (int s = S; s >= 0; s--) {
      for (int p = P; p >= 0; p--) {
        if (f[r][s][p] == 0.0) {
          continue;
        }
        int total = r * s + s * p + p * r; 
        if (total == 0) {
          continue;
        }
        if (r > 0) {
          f[r - 1][s][p] += 1.0 * (p * r) / total * f[r][s][p];
        }
        if (s > 0) {
          f[r][s - 1][p] += 1.0 * (r * s) / total * f[r][s][p];
        }
        if (p > 0) {
          f[r][s][p - 1] += 1.0 * (s * p) / total * f[r][s][p]; 
        }
      }
    }
  }
  double rockSurvive = 0.0, scissorSurvive = 0.0, paperSurvive = 0.0; 
  for (int r = 1; r <= R; r++) {
    rockSurvive += f[r][0][0]; 
  }
  for (int s = 1; s <= S; s++) {
    scissorSurvive += f[0][s][0];
  }
  for (int p = 1; p <= P; p++) {
    paperSurvive += f[0][0][p];
  }
  std::cout << std::fixed << std::setprecision(12) << rockSurvive << ' ' << scissorSurvive << ' ' << paperSurvive; 
  return 0;
}