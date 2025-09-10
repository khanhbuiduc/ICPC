#include <iostream> 
#include <math.h>  
int f[2][1005][53][53]; 
int n, p, k; 
int firstStudent[1005], secondStudent[1005]; 

void update(int &a, int b) {
  a = std::max(a, b); 
}

int calc(int nextPos, int k1, int k2) {
  int ans = 0; 
  if (k1 > 0) {
    ans |= firstStudent[nextPos];
  }
  if (k2 > 0) {
    ans |= secondStudent[nextPos]; 
  }
  return ans; 
}

int main () {
  std::cin >> n >> p >> k; 
  int cnt;
  std::cin >> cnt; 
  for (int i = 1; i <= cnt; i++) {
    int correct;
    std::cin >> correct; 
    firstStudent[correct] = 1; 
  }
  std::cin >> cnt; 
  for (int i = 1; i <= cnt; i++) {
    int correct;
    std::cin >> correct; 
    secondStudent[correct] = 1; 
  }
  int maxCopies = 2 * (n / k + 1); 
  if (p >= maxCopies) {
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      ans += firstStudent[i] | secondStudent[i]; 
    }
    std::cout << ans; 
    return 0; 
  }
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= p; j++) {
      for (int k1 = 0; k1 <= k; k1++) {
        for (int k2 = 0; k2 <= k; k2++) {
          f[i][j][k1][k2] = -1; 
        }
      }
    }
  }
  f[0][0][0][0] = 0; 
  for (int i = 0; i < n; i++) {
    int cur = i & 1; 
    int nxt = !cur; 
    for (int j = 0; j <= p; j++) {
      for (int k1 = 0; k1 <= k; k1++) {
        for (int k2 = 0; k2 <= k; k2++) {
          f[nxt][j][k1][k2] = -1;   
        }
      }
    }
    for (int j = 0; j <= p; j++) {
      for (int k1 = 0; k1 <= k; k1++) {
        for (int k2 = 0; k2 <= k; k2++) {
          if (f[cur][j][k1][k2] == -1) {
            continue; 
          }
          int nextk1 = (k1 == 0 || k1 == k ? 0 : k1 + 1);
          int nextk2 = (k2 == 0 || k2 == k ? 0 : k2 + 1); 
          update(f[nxt][j][nextk1][nextk2], f[cur][j][k1][k2] + calc(i + 1, nextk1, nextk2)); 
          if (j + 1 <= p) {
            update(f[nxt][j + 1][nextk1][1], f[cur][j][k1][k2] + calc(i + 1, nextk1, 1));
            update(f[nxt][j + 1][1][nextk2], f[cur][j][k1][k2] + calc(i + 1, 1, nextk2));  
          } 
          if (j + 2 <= p) {
            update(f[nxt][j + 2][1][1], f[cur][j][k1][k2] + calc(i + 1, 1, 1)); 
          }
        }
      }
    }
  }
  int ans = -1; 
  for (int k1 = 0; k1 <= k; k1++) {
    for (int k2 = 0; k2 <= k; k2++) {
      update(ans, f[n & 1][p][k1][k2]); 
    }
  }
  std::cout << ans; 
  return 0; 
}