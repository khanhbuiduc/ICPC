#include <iostream> 
int a[100005]; 
int f[100005][18]; 
int n, numQuery, M;

int main () {
  std::cin >> n >> numQuery >> M;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int p = 1; 
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 15; j++) {
      f[i][j] = -1; 
    }
  } 
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    while (sum > M) {
      sum -= a[p];
      p++; 
    }
    f[i][0] = p;
  }
  for (int j = 1; j <= 15; j++) {
    for (int i = 1; i <= n; i++) {
      int pos = f[i][j - 1]; 
      if (pos <= 1) {
        continue; 
      }
      pos--; 
      pos = f[pos][j - 1]; 
      if (pos >= 1) {
        f[i][j] = pos; 
      }
    }
  }
  for (int query = 1; query <= numQuery; query++) {
    int u, v;
    std::cin >> u >> v; 
    int pos = u; 
    for (int j = 15; j >= 0; j--) {
      if (f[pos][j] != -1 && v >= (1 << j)) {
        pos = f[pos][j];
        v -= (1 << j); 
        if (pos == 1) {
          break; 
        }
        if (v == 0) {
          break;
        }
        pos--; 
      }
    }
    std::cout << pos << std::endl;
  }
  return 0; 
}