#include <bits/stdc++.h> 

using namespace std; 

int main () {
  freopen("AC1.INP", "r", stdin);
  freopen("AC1.OUT", "w", stdout);
  int test;
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    int c1, c2, c3;
    cin >> c1 >> c2 >> c3; 
    int res = c1 + c2 + c3;
    int type = 1;  
    if (res > 2 * c1 + 2 * c2) {
      res = 2 * c1 + 2 * c2; 
      type = 2; 
    }              
    if (res > 2 * c2 + 2 * c3) {
      res = 2 * c2 + 2 * c3; 
      type = 3; 
    }   
    if (res > 2 * c3 + 2 * c1) {
      res = 2 * c3 + 2 * c1; 
      type = 4; 
    } 
    cout << res << endl;  
  } 
  return 0; 
}