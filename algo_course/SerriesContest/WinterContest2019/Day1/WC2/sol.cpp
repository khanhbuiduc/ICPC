#include <bits/stdc++.h> 

using namespace std; 

int main () {
  freopen("WC2.INP", "r", stdin);
  freopen("WC2.OUT", "w", stdout);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++) {
      cout << j << ' ' << j << endl;
    }
    cout << "##########" << endl;
  }
  return 0; 
}