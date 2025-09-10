#include <iostream>
#include <math.h>
struct day {
  int A, B, C; 
};
int f[100005][3];
int n;
day a[100005];  

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].A >> a[i].B >> a[i].C; 
  }
  f[1][0] = a[1].A;
  f[1][1] = a[1].B;
  f[1][2] = a[1].C;
  for (int i = 1; i <= n; i++) {
    f[i][0] = std::max(f[i - 1][1], f[i - 1][2]) + a[i].A;
    f[i][1] = std::max(f[i - 1][0], f[i - 1][2]) + a[i].B;
    f[i][2] = std::max(f[i - 1][0], f[i - 1][1]) + a[i].C;
  }
  std::cout << std::max(f[n][0], std::max(f[n][1], f[n][2])); 
  return 0; 
}