#include <iostream>
#include <math.h>
#include <vector> 
const int inf = 1000000007; 
int n, m, numTest; 
int a[200005], b[2005]; 
int f[2005][2005]; 
std::vector <int> listPosition[2005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    for (int i = 1; i <= 2000; i++) {
      listPosition[i].clear(); 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      listPosition[a[i]].push_back(i); 
    }
    for (int i = 1; i <= m; i++) {
      std::cin >> b[i]; 
    }
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= i; j++) {
        f[i][j] = inf; 
      }
    }
    f[0][0] = 0; 
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= i; j++) {
        if (f[i][j] == inf) {
          continue; 
        }
        f[i + 1][j] = std::min(f[i + 1][j], f[i][j]); 
        int lo = 0;
        int hi = (int) listPosition[b[i + 1]].size() - 1;
        int pos = -1;  
        while (lo <= hi) {
          int mid = (lo + hi) / 2; 
          if (listPosition[b[i + 1]][mid] > f[i][j]) {
            pos = listPosition[b[i + 1]][mid]; 
            hi = mid - 1; 
          }
          else {
            lo = mid + 1; 
          }
        }
        if (pos != -1) {
          f[i + 1][j + 1] = std::min(f[i + 1][j + 1], pos);
        }
      }
    }
    int res = -1; 
    for (int j = 0; j <= m; j++) {
      if (f[m][j] != inf) {
        res = j; 
      }
    }
    std::cout << res << std::endl; 
  }  
  return 0; 
}