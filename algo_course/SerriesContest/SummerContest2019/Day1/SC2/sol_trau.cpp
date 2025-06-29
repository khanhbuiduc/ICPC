#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 22;
int a[MAX_N], b[MAX_N];
int n, m;  
int test; 

int main () {
  freopen("SC2.INP", "r", stdin);
  freopen("SC2.OUT", "w", stdout); 
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d %d", &n, &m); 
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]); 
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", &b[i]); 
    }
    int res = 0; 
    for (int mask = 1; mask < (1 << n); mask++) {
      bool check = true; 
      for (int i = 0; i < n - 1; i++) {
        if ((mask & (1 << i)) > 0 && (mask & (1 << (i + 1))) > 0) {
          check = false;
          break;   
        }
      }
      if (check == false) {
        continue; 
      }
      vector <int> c; 
      for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) > 0) {
          c.push_back(a[i]); 
        }
      }
      int q = 0; 
      for (int p = 0; p < (int) c.size(); p++) {
        while (q < m && c[p] != b[q]) {
          q++; 
        }
        if (q >= m) {
          check = false; 
          break; 
        }
        else {
          q += 2; 
        }  
      }
      if (check == true) {
        res = max(res, (int) c.size()); 
      } 
    }
    printf("%d\n", res); 
  }
  return 0; 
}