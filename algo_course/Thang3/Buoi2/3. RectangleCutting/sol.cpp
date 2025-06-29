#include <iostream>
#include <math.h> 

using namespace std;
const int inf = 250007;
int f[505][505]; 
int a, b; 

int main () {
  std::cin >> a >> b;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i != j) {
        f[i][j] = inf; 
      }   
    }
  }
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i == j) {
        continue; 
      }
      for (int x = 1; x < i; x++) {
        f[i][j] = std::min(f[i][j], f[x][j] + f[i - x][j] + 1); 
      }
      for (int y = 1; y < j; y++) {
        f[i][j] = std::min(f[i][j], f[i][y] + f[i][j - y] + 1); 
      }
    }
  }  
  cout << f[a][b];
  return 0;
}