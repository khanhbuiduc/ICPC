#include <bits/stdc++.h> 

using namespace std; 
int test; 
int a, b; 
string s; 

int main () {
  //freopen("SC1.INP", "r", stdin);
  //freopen("SC1.OUT", "w", stdout);
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> a >> b; 
    cin >> s; 
    int cur = 0; 
    int lim = 30; 
    for (int i = 0; i < 10; i++) {
      if (lim < a || cur >= b || (cur >= a && lim < b)) {
        cout << '-' << endl; 
        continue;
      }
      else if (s[i] == 'H') {
        cur++;
        lim -= 2;   
      }
      else if (s[i] == 'B') {
        lim -= 3; 
      }
      else {
        cur += 3; 
      }
      cout << lim << endl; 
    }
    if (lim < a) {
      cout << "XUONG_HANG" << endl; 
    }
    else if (cur >= a && lim < b) {
      cout << "KHONG_DOI" << endl; 
    }
    else {
      cout << "THANG_HANG" << endl; 
    }
    cout << "#########" << endl; 
  }
  return 0; 
}