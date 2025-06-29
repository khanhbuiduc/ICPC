#include <iostream>
#include <algorithm>
#include <vector>
const int inf = 1000000007;

struct cow {
  int x, y;
  bool operator < (const cow &hs) const {
    if (y < hs.y || (y == hs.y && x < hs.x)) {
      return true;
    }
    return false;
  }
};

std::vector <cow> listCows;
int f[1005][1005][3];
int n, K, B;
int numTest;

void updateMin(int &a, int b) {
  a = std::min(a, b);
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> K >> B;
    listCows.clear();
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= K; j++) {
        for (int status = 0; status < 3; status++) {
          f[i][j][status] = inf;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      int x, y;
      std::cin >> x >> y;
      listCows.push_back((cow) {x, y});
    }
    std::sort(listCows.begin(), listCows.end());
    f[1][1][0] = 1;
    f[1][1][1] = 2;
    if (K >= 2) {
      f[1][2][2] = 2;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= K; j++) {
        for (int status = 0; status <= 2; status++) {
          if (f[i][j][status] == inf) {
            continue;
          }
          int val = f[i][j][status];
          if (j + 1 <= K) {
            updateMin(f[i + 1][j + 1][0], val + 1);
            updateMin(f[i + 1][j + 1][1], val + 2);
            if (j + 2 <= K) {
              updateMin(f[i + 1][j + 2][2], val + 2);
            }
          }
          if (status == 0) {
            if (j + 1 <= K) {
              updateMin(f[i + 1][j + 1][2], val + listCows[i].y - listCows[i - 1].y + 1); 
            }
            if (listCows[i].x == listCows[i - 1].x) {
              updateMin(f[i + 1][j][0], val + listCows[i].y - listCows[i - 1].y); 
            }
          }
          else if (status == 1) {
            updateMin(f[i + 1][j][1], val + 2 * (listCows[i].y - listCows[i - 1].y)); 
          }  
          else {
            if (j + 1 <= K) {
              updateMin(f[i + 1][j + 1][2], val + listCows[i].y - listCows[i - 1].y + 1); 
            }
            if (listCows[i].x != listCows[i - 1].x) {
              updateMin(f[i + 1][j][0], val + listCows[i].y - listCows[i - 1].y); 
            }
            updateMin(f[i + 1][j][2], val + 2 * (listCows[i].y - listCows[i - 1].y)); 
          }
        }
      }
    }
    int ans = inf;
    for (int status = 0; status <= 2; status++) {
      updateMin(ans, f[n][K][status]); 
    }
    std::cout << ans << std::endl;
  }
  return 0;
}                                                                                  