#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 15; 
int a[MAX_N]; 
int d[MAX_N];
int test, n, deno, nume; 
bool mark[MAX_N];

void backTrack(int pos) {
  if (pos == n + 1) {
    nume++; 
    for (int i = 1; i <= n; i++) {
      deno += abs(d[i] - d[i - 1]); 
    }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (mark[i] == false) {
      mark[i] = true; 
      d[pos] = a[i];
      backTrack(pos + 1); 
      mark[i] = false; 
    }
  }  
}

int main () {
  freopen("SPC2.INP", "r", stdin);
  freopen("SPC2.OUT", "w", stdout); 
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]); 
      mark[i] = false; 
      d[i] = 0;
    }
    deno = nume = 0; 
    backTrack(1);                        
    int gcd = __gcd(deno, nume);
    deno /= gcd;
    nume /= gcd;
    printf("%d %d\n", deno, nume);
  }
  return 0; 
}