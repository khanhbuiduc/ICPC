#include <iostream>
#include <iomanip>
double f[102][8][8]; 
int steps; 
double ans = 0.0;
double probNotReach[8][8];

int canReach(int x, int y) {
  int ret = 0; 
  if (x < 7) {
    ret++; 
  }
  if (y < 7) {
    ret++;
  }
  if (x > 0) {
    ret++;
  }
  if (y > 0) {
    ret++; 
  }
  return ret; 
}

int main () {
  std::cin >> steps; 
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      probNotReach[x][y] = 1.0; 
    }
  }
  for (int startx = 0; startx < 8; startx++) {
    for (int starty = 0; starty < 8; starty++) {
      for (int i = 0; i <= steps; i++) {
        for (int x = 0; x < 8; x++) {
          for (int y = 0; y < 8; y++) {
            f[i][x][y] = 0.0; 
          }
        }
      }
      f[0][startx][starty] = 1.0; 
      for (int i = 0; i < steps; i++) {
        for (int x = 0; x < 8; x++) {
          for (int y = 0; y < 8; y++) {
            if (f[i][x][y] == 0.0) {
              continue; 
            }                                                                           
            int numbValids = canReach(x, y);
            if (x < 7) {
              f[i + 1][x + 1][y] += (1.0 / numbValids) * f[i][x][y];
            } 
            if (x > 0) {
              f[i + 1][x - 1][y] += (1.0 / numbValids) * f[i][x][y];
            }
            if (y < 7) {
              f[i + 1][x][y + 1] += (1.0 / numbValids) * f[i][x][y];
            }
            if (y > 0) {
              f[i + 1][x][y - 1] += (1.0 / numbValids) * f[i][x][y];
            }
          }
        }
      }
      for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
          probNotReach[x][y] *= (1.0 - f[steps][x][y]);  
        }
      }
    }
  }                             
  double ans = 0.0; 
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      ans += probNotReach[x][y]; 
    }
  }
  std::cout << std::fixed << std::setprecision(6) << ans;
  return 0; 
}