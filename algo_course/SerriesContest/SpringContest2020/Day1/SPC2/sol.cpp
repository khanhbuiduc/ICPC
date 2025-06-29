#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 
int a[MAX_N]; 
int test, n; 

int main () {
  freopen("SPC2.INP", "r", stdin);
  freopen("SPC2.OUT", "w", stdout); 
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d", &n); 
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]); 
    }
    long long deno = 0, nume = 1LL * n; 
    sort(a + 1, a + n + 1); 
    long long S = 0LL;
    for (int i = 1; i <= n; i++) {
      S += 1LL * a[i]; 
    }
    deno = S; 
    long long curSum = 0LL; 
    for (int i = 1; i <= n; i++) {
      curSum += 1LL * a[i]; 
      deno += 1LL * S; 
      deno -= 2LL * curSum; 
      deno += 1LL * (2 * i - n) * a[i]; 
    }                                         
    long long gcd = __gcd(deno, nume); 
    deno /= gcd;
    nume /= gcd; 
    printf("%lld %lld\n", deno, nume); 
  }
  return 0; 
}