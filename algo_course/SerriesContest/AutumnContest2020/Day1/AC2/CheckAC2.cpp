#include <bits/stdc++.h>
 
using namespace std;
const int MAX_N = 52;
const int inf = 1005;
int dp[MAX_N][MAX_N];
int value[MAX_N];
int maxi[MAX_N], mini[MAX_N];
 
struct element {
  int n, g, k;
  vector <int> a;
};
vector <element> inp;
vector <string> out;
 
int toInt(const string &s) {
  int res = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    res = res * 10 + s[i] - '0';
  }
  return res;
}
 
vector <int> split(string s) {
  while (s.back() == ' ') {
    s.pop_back();
  }
  s += ' ';
  string st = "";
  vector <int> res;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == ' ') {
      res.push_back(toInt(st));
      st = "";
    }
    else {
      st += s[i];
    }
  }
  return res;
}
 
bool canDivide(const element &E) {
  int n = E.n;
  int g = E.g;
  int k = E.k;
  for (int i = 0; i < n; i++) {
    value[i + 1] = E.a[i];
  }
  sort(value + 1, value + n + 1);
  for (int group = 0; group <= g; group++) {
    for (int i = 0; i <= n; i++) {
      dp[i][group] = inf;
    }
  }
  dp[0][0] = 0;
  for (int group = 0; group < g; group++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][group] == inf) {
        continue;
      }
      dp[i + 1][group + 1] = min(dp[i + 1][group + 1], dp[i][group]);
      if (i + 2 <= n) {
        for (int j = i + 2; j <= n; j++) {
          dp[j][group + 1] = min(dp[j][group + 1], dp[i][group] + value[j] - value[i + 1]);
        }
      }
    }
  }
  if (dp[n][g] > k) {
    return true;
  }
  else {
    return false;
  }
}
 
bool compare(const element &E, string &s) {
  bool check = canDivide(E);
  if (check == true && s != "IMPOSSIBLE") {
    return false;
  }
  else if (check == false && s == "IMPOSSIBLE") {
    return false;
  }
  if (check == true && s == "IMPOSSIBLE") {
    return true;
  }
  vector <int> group = split(s);
  vector <int> a = E.a;
  int n = E.n;
  int g = E.g;
  int k = E.k;
  assert(n == (int) group.size());
  for (int i = 0; i < n; i++) {
    assert(1 <= group[i] && group[i] <= g);
  }
  for (int i = 1; i <= g; i++) {
    maxi[i] = -1;
    mini[i] = 105;
  }
  for (int i = 0; i < n; i++) {
    maxi[group[i]] = max(maxi[group[i]], a[i]);
    mini[group[i]] = min(mini[group[i]], a[i]);
  }
  for (int i = 1; i <= g; i++) {
    assert(mini[i] < 105);
    assert(maxi[i] > -1);
  }
  int sum = 0;
  for (int i = 1; i <= g; i++) {
    sum += maxi[i] - mini[i];
  }
  if (sum > k) {
    return false;
  }
  else {
    return true;
  }
}
 
bool Test() {
  if ((int) inp.size() != (int) out.size()) {
    return false;
  }
  for (int i = 0; i < (int) inp.size(); i++) {
    if (compare(inp[i], out[i]) == false) {
      return false;
    }
  }
  return true;
}
 
int main () {
  freopen("AC2.INP", "r", stdin);
  cin.clear();
  int test;
  cin >> test;
  for (int i = 1; i <= test; i++) {
    int n, g, k;
    cin >> n >> g >> k;
    vector <int> a;
    for (int j = 1; j <= n; j++) {
      int v;
      cin >> v;
      a.push_back(v);
    }
    inp.push_back((element) {n, g, k, a});
  }
  cin.clear();
  freopen("AC2.OUT", "r", stdin);
  string s;
  while (getline(cin, s)) {
    out.push_back(s);
  }
  bool check = Test();
  if (check == false) {
    cout << "Wrong Answer" << endl;
    cout << 0.0 << endl;
  }
  else {
    cout << "Correct!!" << endl;
    cout << 1.0 << endl;
  }
  return 0;
}