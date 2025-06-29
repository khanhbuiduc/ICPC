#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 500005; 
int a[MAX_N];
int F[MAX_N];
int n;
int test; 

int main () {
  freopen("WC6.INP", "r", stdin);
  freopen("WC6.OUT", "w", stdout);
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d", &n);
    long long sum = 0LL;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += 1LL * a[i];
    }
    if (sum % 3 != 0) {
      printf("0\n");
      continue;
    }
    long long part = sum / 3;
    sum = 0;
    F[n + 1] = 0; 
    for (int i = n; i >= 1; i--) {
      sum += a[i];
      F[i] = F[i + 1];
      if (part == sum) {
        F[i]++;
      }    
    }                       
    long long res = 0LL;
    sum = 0LL;
    for (int i = 1; i <= n - 2; i++) {
      sum += a[i];
      if (sum == part) {
        res += F[i + 2];
      }  
    }
    printf("%lld\n", res);
  }
  return 0; 
}