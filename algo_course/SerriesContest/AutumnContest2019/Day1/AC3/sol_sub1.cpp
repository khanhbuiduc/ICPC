#include <bits/stdc++.h> 

using namespace std; 
int test; 
struct segment {
  int l, r; 
  bool operator < (const segment &hs) const {
    return (l < hs.l || (l == hs.l && r < hs.r));
  }
};
segment a[20]; 
int n, k; 

int main () {
  freopen("AC3.INP", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i].l >> a[i].r;
    }  
    int res = -1; 
    for (int mask = 1; mask < (1 << n); mask++) {
      int cnt = __builtin_popcount(mask); 
      if (cnt != k) {
        continue; 
      }
      int maxL = -1; 
      int minR = 1000000007; 
      for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) > 0) {
          maxL = max(maxL, a[i].l);
          minR = min(minR, a[i].r); 
        }
      }
      res = max(res, max(0, minR - maxL + 1)); 
    }
    cout << res << endl; 
  }
  return 0; 
}