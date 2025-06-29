#include <iostream>
#include <cstring>

const int MOD = 998244353;
int f[40][40][3][40][3][40][3];
bool skill[40][2];
int n, d;
int numTest;

void update(int &a, int b) {
  (a += b) %= MOD;
}

void dynamicProgramming() {
  std::memset(f, 0, sizeof(f));
  f[0][0][0][0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int dRemain = 0; dRemain <= d + 1; dRemain++) {
      for (int friendRemain = 0; friendRemain <= 2; friendRemain++) {
        for (int dSing = 0; dSing <= d + 1; dSing++) {
          for (int friendSing = 0; friendSing <= 2; friendSing++) {
            for (int dDance = 0; dDance <= d + 1; dDance++) {
              for (int friendDance = 0; friendDance <= 2; friendDance++) {
                if (f[i][dRemain][friendRemain][dSing][friendSing][dDance][friendDance] == 0) {
                  continue;
                }
                int curValue = f[i][dRemain][friendRemain][dSing][friendSing][dDance][friendDance];
                if (friendRemain == 0) {
                  update(f[i + 1][0][1][std::min(dSing + 1, d + 1)][friendSing][std::min(dDance + 1, d + 1)][friendDance], curValue);
                }
                if (friendRemain == 1 && dRemain < d) {
                  update(f[i + 1][0][2][std::min(dSing + 1, d + 1)][friendSing][std::min(dDance + 1, d + 1)][friendDance], curValue);
                }
                if (friendRemain == 2) {
                  if (dRemain < d) {
                    update(f[i + 1][0][2][std::min(dSing + 1, d + 1)][friendSing][std::min(dDance + 1, d + 1)][friendDance], curValue);
                  }
                  else {
                    update(f[i + 1][0][1][std::min(dSing + 1, d + 1)][friendSing][std::min(dDance + 1, d + 1)][friendDance], curValue);  
                  }
                }
                if (skill[i + 1][0] == true) {
                  if (friendSing == 0) {
                    update(f[i + 1][std::min(dRemain + 1, d + 1)][friendRemain][0][1][std::min(dDance + 1, d + 1)][friendDance], curValue);
                  }
                  if (friendSing == 1 && dSing < d) {
                    update(f[i + 1][std::min(dRemain + 1, d + 1)][friendRemain][0][2][std::min(dDance + 1, d + 1)][friendDance], curValue);
                  }
                  if (friendSing == 2) {
                    if (dSing < d) {
                      update(f[i + 1][std::min(dRemain + 1, d + 1)][friendRemain][0][2][std::min(dDance + 1, d + 1)][friendDance], curValue);
                    }
                    else {
                      update(f[i + 1][std::min(dRemain + 1, d + 1)][friendRemain][0][1][std::min(dDance + 1, d + 1)][friendDance], curValue);
                    }
                  }
                }
                if (skill[i + 1][1] == true) {
                  if (friendDance == 0) {
                    update(f[i + 1][std::min(dRemain + 1, d + 1)][friendRemain][std::min(dSing + 1, d + 1)][friendSing][0][1], curValue);
                  }
                  if (friendDance == 1 && dDance < d) {
                    update(f[i + 1][std::min(dRemain + 1, d + 1)][friendRemain][std::min(dSing + 1, d + 1)][friendSing][0][2], curValue);
                  }
                  if (friendDance == 2) {
                    if (dDance < d) {
                      update(f[i + 1][std::min(dRemain + 1, d + 1)][friendRemain][std::min(dSing + 1, d + 1)][friendSing][0][2], curValue);
                    }
                    else {
                      update(f[i + 1][std::min(dRemain + 1, d + 1)][friendRemain][std::min(dSing + 1, d + 1)][friendSing][0][1], curValue);
                    }
                  } 
                }
              }
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int dRemain = 0; dRemain <= d + 1; dRemain++) {
    for (int dSing = 0; dSing <= d + 1; dSing++) {
      for (int dDance = 0; dDance <= d + 1; dDance++) {
        update(ans, f[n][dRemain][0][dSing][2][dDance][2]);
        update(ans, f[n][dRemain][2][dSing][2][dDance][2]);
      }
    }
  }
  std::cout << ans << std::endl;
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      skill[i][0] = false;
      skill[i][1] = false;
    }
    int numSing, numDance;
    std::cin >> numSing;
    for (int i = 1; i <= numSing; i++) {
      int id;
      std::cin >> id;
      skill[id][0] = true;
    }
    std::cin >> numDance;
    for (int i = 1; i <= numDance; i++) {
      int id;
      std::cin >> id;
      skill[id][1] = true;
    }
    dynamicProgramming();
  }
  return 0; 
}