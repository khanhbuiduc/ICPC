#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX_N = 100005;
const int MAX_TYPE = 105;
struct element {
  int type, cost;
  bool operator < (const element &other) const {
    return cost < other.cost;
  }
};
element a[MAX_N];
int K, C;
int n, numTest;
bool isSelected[MAX_TYPE];
bool mark[MAX_N];

int main () {
  freopen("SC4.INP", "r", stdin);
  freopen("SC4.OUT", "w", stdout);
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    scanf("%d %d %d", &n, &K, &C);
    for (int type = 1; type < MAX_TYPE; type++) {
      isSelected[type] = false;
    }
    memset(mark, false, sizeof(mark));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].type);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].cost);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      if (K == 0) {
        break;
      }
      if (isSelected[a[i].type] == false) {
        if (C >= a[i].cost) {
          C -= a[i].cost;
          K--;
          isSelected[a[i].type] = true;
          mark[i] = true;
        }
        else {
          break;
        }
      }
    }
    if (K > 0) {
      cout << "FRIENDSHIP" << endl;
    }
    else {
      bool check = false;
      for (int i = 1; i <= n; i++) {
        if (mark[i] == false && C >= a[i].cost) {
          check = true;
          break;
        }
      }
      if (check == true) {
        cout << "LOVE" << endl;
      }
      else {
        cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
      }
    }
  }
  return 0;
}