#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 
const long long MOD = 68718952446;
long long F[MAX_N], invF[MAX_N]; 
int n, test;
long long a[MAX_N]; 

int main () {
  freopen("WC1.INP", "r", stdin);
  freopen("WC1.OUT", "w", stdout); 
  scanf("%d", &test);
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d", &n); 
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]); 
    }
    F[0] = 1LL; 
    invF[n + 1] = 1LL; 
    for (int i = 1; i <= n; i++) {
      F[i] = (F[i - 1] * a[i]) % MOD; 
    }
    for (int i = n; i >= 1; i--) {
      invF[i] = (invF[i + 1] * a[i]) % MOD; 
    }
    for (int i = 1; i <= n; i++) {
      cout << (F[i - 1] * invF[i + 1]) % MOD << ' '; 
    }
    cout << endl; 
  }
  return 0; 
}