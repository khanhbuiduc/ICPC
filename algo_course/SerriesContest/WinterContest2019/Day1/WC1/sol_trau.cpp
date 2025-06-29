#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 1005; 
const long long MOD = 68718952446LL; 
int T; 
int n; 
int a[MAX_N];

int main () {
  freopen("input.txt", "r", stdin);
  freopen("WC1.OUT", "w", stdout);
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }  
    for (int i = 1; i <= n; i++) {   
      long long res = 1LL;
      for (int j = 1; j <= n; j++) {
        if (i != j) {
          (res *= 1LL * a[j]) %= MOD;
        }
      }
      cout << res << ' ';
    }
    cout << endl;
  }
  return 0; 
}