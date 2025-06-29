#include <bits/stdc++.h>

using namespace std;

int distance(int a, int b) {
  if (a > b) {
    swap(a, b);
  }
  return min(b - a, 26 + a - b);
}

int solve(string s) {
  int res = 100000007;
  vector <int> v;
  for (int c = 0; c < 26; c++) {
    int cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] - 'a' == c) {
        cnt++;
      }
    }
    if (cnt % 2 == 1) {
      v.push_back(c);
    }
  }
  int sz = (int) v.size();
  if (sz <= 1) {
    return 0;
  }
  else {
    int step = sz / 2;
    for (int i = 0; i < (int) v.size(); i++) {
      int p = i;
      int sum = 0;
      for (int j = 1; j <= step; j++) {
        int cur = p;
        int nxt = (p + 1) % sz;
        sum += distance(v[cur], v[nxt]);
        p = (nxt + 1) % sz;
      }
      res = min(res, sum);
    }
  }
  return res;
}

int numTest;
string s; 

int main () {
  freopen("AC5.INP", "r", stdin);
  freopen("AC5.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    cout << solve(s) << endl; 
  }
  return 0;
}