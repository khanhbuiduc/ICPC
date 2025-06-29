#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 
struct segment {
  int l, r; 
  bool operator < (const segment &hs) const {
    return (l < hs.l || (l == hs.l && r < hs.r));
  }
};
int test; 
priority_queue <int, vector <int>, greater <int> > pq; 
int n, k; 
segment a[MAX_N]; 

int main () {
  freopen("AC3.INP", "r", stdin);
  freopen("AC3.OUT", "w", stdout);
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].l >> a[i].r;
    } 
    while (pq.empty() == false) {
      pq.pop(); 
    }
    sort(a + 1, a + n + 1); 
    for (int i = 1; i <= k; i++) {
      pq.push(a[i].r);   
    }
    int res = max(0, pq.top() - a[k].l + 1); 
    for (int i = k + 1; i <= n; i++) {
      pq.pop(); 
      pq.push(a[i].r);
      res = max(res, max(0, pq.top() - a[i].l + 1)); 
    }
    cout << res << endl; 
  }
  return 0; 
}