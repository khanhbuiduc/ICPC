#include <bits/stdc++.h> 

using namespace std; 
int test; 
long long n, m, a, b; 

int main () {
  freopen("SC5.INP", "r", stdin);
  freopen("SC5.OUT", "w", stdout);
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> m >> a >> b; 
    a--;
    long long curx = 1; 
    long long cury = 1;
    while (a > 0) {
      if (curx & 1) {
        cury++; 
      }
      else {
        cury--; 
      }
      if (cury == m + 1) {
        cury = m; 
        curx++; 
      }
      else if (cury == 0) {
        cury = 1;
        curx++;  
      }
      a--; 
    }
    long long x1 = curx; 
    long long y1 = cury; 
    while (b > 0) {
      if (curx & 1) {
        cury++; 
      }
      else {
        cury--; 
      }
      if (cury == m + 1) {
        cury = m; 
        curx++; 
      }
      else if (cury == 0) {
        cury = 1;
        curx++;  
      }
      b--; 
    }
    long long x2 = curx; 
    long long y2 = cury;
    cout << abs(x1 - x2) + abs(y1 - y2) << endl; 
  }
  return 0; 
}