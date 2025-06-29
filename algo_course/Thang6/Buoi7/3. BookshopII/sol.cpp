#include <iostream>
#include <math.h>
#include <vector> 
const int inf = -1; 
struct book {
  int price, pages; 
};
std::vector <book> a; 
int n; 
int M; 
int f[2][100005];
int price[105], pages[105], copies[105];  
 
int main () {
  std::cin >> n >> M; 
  for (int i = 1; i <= n; i++) {
    std::cin >> price[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> pages[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> copies[i];
  }
  for (int i = 1; i <= n; i++) {
    int numb = 1;
    int total = 0;  
    while (numb <= copies[i]) {
      copies[i] -= numb; 
      a.push_back((book) {price[i] * numb, pages[i] * numb});
      numb *= 2; 
      if (numb > copies[i]) {
        break;
      }
    }
    if (copies[i] > 0) {
      a.push_back((book) {price[i] * copies[i], pages[i] * copies[i]}); 
    }
  }
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= M; j++) {
      f[i][j] = inf; 
    }
  }
  n = (int) a.size(); 
  for (int j = 0; j <= M; j++) {
    f[0][j] = 0; 
  }
  for (int i = 0; i < n; i++) {
    int cur = i % 2; 
    int nxt = 1 - cur; 
    for (int j = 0; j <= M; j++) {
      f[nxt][j] = inf; 
    }
    for (int j = 0; j <= M; j++) {
      if (f[cur][j] == inf) {
        continue; 
      }
      f[nxt][j] = std::max(f[nxt][j], f[cur][j]); 
      if (j + a[i].price <= M) {
        f[nxt][j + a[i].price] = std::max(f[nxt][j + a[i].price], f[cur][j] + a[i].pages); 
      }
    } 
  }
  std::cout << f[n % 2][M]; 
  return 0;
}