#include <iostream> 
#include <math.h> 
#include <string> 
const int inf = 7000005; 
int cost[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500}; 
int fMin[10][70005], fMax[10][70005]; 
int a[9], b[9]; 
int n, C, numTest; 

void init() {
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 70000; j++) {
      fMin[i][j] = inf; 
      fMax[i][j] = -inf; 
    }
  }
}

void dynamicProgrammingForMax() {
  fMax[0][0] = 0; 
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j <= 70000; j++) {
      if (fMax[i][j] == -inf) {
        continue; 
      }
      for (int x = 0; x <= a[i]; x++) {
        fMax[i + 1][j + x * cost[i]] = std::max(fMax[i + 1][j + x * cost[i]], fMax[i][j] + x); 
      }
    }
  }
}

void dynamicProgrammingForMin() {
  fMin[0][0] = 0; 
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j <= 70000; j++) {
      if (fMin[i][j] == inf) {
        continue; 
      }
      for (int x = 0; x <= b[i]; x++) {
        fMin[i + 1][j + x * cost[i]] = std::min(fMin[i + 1][j + x * cost[i]], fMin[i][j] + x); 
      }
    }
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> C; 
    C /= 1000; 
    for (int i = 0; i < 9; i++) {
      std::string s;
      std::cin >> s >> a[i] >> b[i];    
    }
    init();
    dynamicProgrammingForMax();
    dynamicProgrammingForMin();
    int ans = inf; 
    for (int X = C; X <= 70000; X++) {
      if (fMax[9][X] != -inf && fMin[9][X - C] != inf) {
        ans = std::min(ans, a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] - fMax[9][X] + fMin[9][X - C]); 
      }
    }                                                         
    if (ans == inf) {
      std::cout << "SORRY!!!" << std::endl; 
    }
    else {
      std::cout << ans << std::endl; 
    }
  }
  return 0; 
}