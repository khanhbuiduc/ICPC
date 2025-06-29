#include <iostream>
using namespace std;
const int MAX_N = 200005;
int n, k, numTest;
int a[MAX_N];

int main () {
  freopen("SPC3.INP", "r", stdin);
  freopen("SPC3.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int count0 = 0;
    int l = 1;
    int res = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) {
        count0++;
      }
      while (count0 > k) {
        if (a[l] == 0) {
          count0--;
        }
        l++;
      }
      if (res < i - l + 1) {
        res = i - l + 1;
      }
    }
    cout << res << endl;
  }
  return 0;
}