#include <iostream> 
#include <math.h> 
const int inf = 33 * 33 * 33 * 33;
int numTest; 
int f[33][33][55]; 
int N, M, K; 

void dynamicProgramming() {
  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= 30; j++) {
      for (int k = 0; k <= 50; k++) {
        if (k == i * j || k == 0) {
          continue; 
        }  
        f[i][j][k] = inf; 
      }
    }
  }
  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= 30; j++) {
      for (int k = 1; k <= std::min(i * j, 50); k++) {
        if (f[i][j][k] == inf) {
          for (int u = 1; u < i; u++) {
            for (int x = 0; x <= k; x++) {
              if (f[u][j][x] != inf && f[i - u][j][k - x] != inf) {
                f[i][j][k] = std::min(f[i][j][k], f[u][j][x] + f[i - u][j][k - x] + j * j); 
              }
            }
          }
          for (int v = 1; v < j; v++) {
            for (int y = 0; y <= k; y++) {
              if (f[i][v][y] != inf && f[i][j - v][k - y] != inf) {
                f[i][j][k] = std::min(f[i][j][k], f[i][v][y] + f[i][j - v][k - y] + i * i); 
              }
            }
          }
        }
      }
    }
  }
}

int main () {
  dynamicProgramming(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> N >> M >> K; 
    std::cout << f[N][M][K] << std::endl; 
  }
  return 0; 
}