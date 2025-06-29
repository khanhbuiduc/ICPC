#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 32; 
int test; 
int a[MAX_N]; 
int n, K, T; 

int main () {
  freopen("SPC4.INP", "r", stdin);
  freopen("SPC4.OUT", "w", stdout); 
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d %d %d", &n, &K, &T); 
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]); 
    }
    int first = 0; 
    int second = 0;
    for (int i = n; i >= 1; i -= 2) {
      first += a[i]; 
    }
    for (int i = n - 1; i >= 1; i -= 2) {
      second += a[i]; 
    }                                       
    if (first < second) {
      cout << "LOSE"; 
    }
    else if (first == second) {
      cout << "DRAW"; 
    }
    else {
      cout << "WIN"; 
    }
    cout << endl; 
  }
  return 0; 
}