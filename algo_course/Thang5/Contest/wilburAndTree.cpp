#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
int a[2005];
int n, h;
double f[2005][2005][2][2], prob[2005][2005][2][2];
double probFallen; 
int left[2005], right[2005]; 

int main () {
  std::cin >> n >> h >> probFallen;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + n + 1);
  a[0] = a[1] - 2 * h;
  a[n + 1] = a[n] + 2 * h;
  for (int i = 1; i <= n; i++) {
    left[i] = i; 
    for (int j = i - 1; j >= 1; j--) {
      if (a[left[i]] - a[j] < h) {
        left[i] = j; 
      }
    }
    right[i] = i; 
    for (int j = i + 1; j <= n; j++) {
      if (a[j] - a[right[i]] < h) {
        right[i] = j; 
      }
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    for (int L = 0; L <= 1; L++) {
      for (int R = 0; R <= 1; R++) {
        prob[i][i - 1][L][R] = 1.0; 
      }
    } 
  }                         
  for (int j = 1; j <= n; j++) {
    for (int i = j; i >= 1; i--) {
      for (int L = 0; L <= 1; L++) {
        for (int R = 0; R <= 1; R++) {
          if (L == 1 && a[i - 1] + h > a[i]) {
            continue; 
          }
          if (R == 0 && a[j + 1] - h < a[j]) {
            continue; 
          }
          int cover = 0; 
          // left tree falls left
          if (L == 0) {
            cover = std::min(h, a[i] - a[i - 1]); 
          } 
          else {
            cover = std::min(h, a[i] - (a[i - 1] + h)); 
          }
          f[i][j][L][R] += f[i + 1][j][0][R] * 0.5 * probFallen + 0.5 * probFallen * cover; 
          prob[i][j][L][R] += prob[i + 1][j][0][R] * 0.5 * probFallen; 
          // left tree falls right
          int r = std::min(j, right[i]);
          cover = a[r] - a[i]; 
          if (r + 1 <= j) {
            cover += h; 
          }
          else {
            if (R == 1) {
              cover += std::min(h, a[j + 1] - a[j]); 
            }  
            else {
              cover += std::min(h, a[j + 1] - h - a[j]); 
            }
          }
          f[i][j][L][R] += f[r + 1][j][1][R] * 0.5 * (1.0 - probFallen) + 0.5 * (1.0 - probFallen) * cover; 
          prob[i][j][L][R] += prob[r + 1][j][1][R] * 0.5 * (1.0 - probFallen); 
          // right tree falls left
          int l = std::max(i, left[j]); 
          cover = a[j] - a[l];
          if (l - 1 >= i) {
            cover += h; 
          } 
          else {
            if (L == 0) {
              cover += std::min(h, a[i] - a[i - 1]); 
            }
            else {
              cover += std::min(h, a[i] - (a[i - 1] + h)); 
            }
          }
          f[i][j][L][R] += f[i][l - 1][L][0] * 0.5 * probFallen + 0.5 * probFallen * cover; 
          prob[i][j][L][R] += prob[i][l - 1][L][0] * 0.5 * probFallen; 
          // right tree falls right
          if (R == 0) {
            cover = std::min(h, a[j + 1] - h - a[j]); 
          }
          else {
            cover = std::min(h, a[j + 1] - a[j]); 
          }
          f[i][j][L][R] += f[i][j - 1][L][1] * 0.5 * (1.0 - probFallen) + 0.5 * (1.0 - probFallen) * cover; 
          prob[i][j][L][R] += prob[i][j - 1][L][1] * 0.5 * probFallen; 
        }
      }
    }
  }
  std::cout << std::fixed << std::setprecision(12) << f[1][n][0][1];
  return 0;
}