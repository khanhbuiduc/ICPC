#include <iostream>

using namespace std;
const int MAX_N = 105;
int a[MAX_N];
int n, k, numTest;

int main () {
  freopen("SPC3.INP", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int res = -1;
    for (int l = 1; l <= n; l++) {
      for (int r = l; r <= n; r++) {
        int count0 = 0;
        for (int t = l; t <= r; t++) {
          if (a[t] == 0) {
            count0++;
          }
        }
        if (count0 <= k) {
          res = max(res, r - l + 1);
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}