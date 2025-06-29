#include <bits/stdc++.h> 

using namespace std; 
int test; 
int A, B, C; 

int main () {
  freopen("AC1.INP", "r", stdin);
  freopen("AC11.OUT", "w", stdout);
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    cin >> A >> B >> C;
    int res = 0; 
    for (int x = 0; x <= A; x++) {
      for (int y = 0; y <= B; y++) {
        if ((x ^ y) <= C) {
          res++;
        }
      }
    }  
    cout << res << endl; 
  }
  return 0; 
}