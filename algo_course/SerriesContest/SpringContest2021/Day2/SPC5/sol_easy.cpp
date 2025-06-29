#include <iostream>
#include <string>

using namespace std;
const long long MOD = 1000000007;
const int MAX_N = 305;
int numTest;
string s;
long long POW2[MAX_N];

int main () {
  freopen("SPC5.INP", "r", stdin);
  freopen("output.txt", "w", stdout);
  POW2[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    POW2[i] = (POW2[i - 1] * 2LL) % MOD;
  }
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    int n = (int) s.size();
    if (s[0] == '_' || s[n - 1] == '_') {
      cout << 0 << endl;
      continue;
    }
    if (n >= 3) {
      if (s[0] == 'T' && s[1] == 'T' && s[2] == 'T') {
        cout << 0 << endl;
        continue;
      }
      else if (s[n - 1] == 'T' && s[n - 2] == 'T' && s[n - 3] == 'T') {
        cout << 0 << endl;
        continue;
      }
    }
    int countT = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'T') {
        countT++;
      }
    }
    if (countT == 2) {
      if (n == 2) {
        cout << 0 << endl;
      }
    else {
        cout << 1 << endl;
      }
    }
    else {
      int numb = 0;
      int l = -1;
      int r = -1;
      for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
          numb++;
          if (numb == 2) {
            l = i;
          }
          else if (numb == 3) {
            r = i;
          }
        }
      }
      int ans = 0;
      if (s[1] == '_' && s[n - 2] == '_') {
        ans = 1;
      }
      int len = r - l - 1;
      if (len > 0) {
        ans = 0;
      }
      (ans += POW2[len]) %= MOD;
      if (s[1] == 'T') {
        ans--;
        if (ans < 0) {
          ans += MOD;
        }
      }
      if (s[n - 2] == 'T') {
        ans--;
        if (ans < 0) {
          ans += MOD;
        }
      }
      (ans += POW2[len]) %= MOD;
      ans--;
      if (ans < 0) {
        ans += MOD;
      }
      if (l == 1 && r == n - 2) {
        ans--;
        if (ans < 0) {
          ans += MOD;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}