#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 
long long F[MAX_N], revF[MAX_N]; 
int n, T;
int a[MAX_N]; 
const long long MOD = 68718952446LL; 

long long mult(long long a, long long b) {
  if (b == 0) {
    return 0LL;
  }
  long long tmp = mult(a, b / 100000); 
  (tmp *= 1LL * 100000LL) %= MOD; 
  if (b % 100000) {
    (tmp += 1LL * (b % 100000) * a) %= MOD; 
  }
  return tmp; 
}
                  

int main () {
  freopen("SPC3.OUT", "r", stdin);
  cin >> T; 
  bool check = false;
  if (T > 20 || T <= 0) {
    cout << "Wrong answer" << endl;
    cout << 0.0;
    return 0; 
  }
  for (int tt = 1; tt <= T; tt++) {
    cin >> n;
    if (n < 1 || n > 100000) {
      break; 
    }
    bool canBreak = false; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] < 1 || a[i] > 1000) {
        canBreak = true;  
      } 
    }
    if (canBreak == true) {
      break; 
    }
    F[0] = 1LL;
    bool flag = true;
    revF[n + 1] = 1LL;
    for (int i = 1; i <= n; i++) {
      F[i] = (F[i - 1] * a[i]) % MOD; 
    }
    for (int i = n; i >= 1; i--) {
      revF[i] = (revF[i + 1] * a[i]) % MOD; 
    }
    for (int i = 1; i <= n; i++) {
      long long x = F[i - 1];
      x = mult(x, revF[i + 1]); 
      long long k = F[i - 1]; 
      (k *= revF[i + 1]) %= MOD; 
      if (x != k) {
        flag = false;         
        break; 
      }
    }
    if (flag == false) {
      check = true;
      break;  
    }            
  }
  if (check == true) {
    cout << "Correct!" << endl;
    cout << 1.0 << endl; 
  }
  else {
    cout << "Wrong answer" << endl; 
    cout << 0.0 << endl; 
  }
  return 0; 
}