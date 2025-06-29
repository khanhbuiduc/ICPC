#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 5005; 
int numTest; 
int w[MAX_N]; 
int n; 
int numbSmaller[MAX_N]; 

int main () {
  freopen("SC4.INP", "r", stdin);
  freopen("SC4.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> w[i]; 
    }
    memset(numbSmaller, 0, sizeof(numbSmaller)); 
    long long ans = 0; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        if (w[j] < w[i]) {
          numbSmaller[i]++; 
        }
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      int numbBigger = 0; 
      for (int j = i + 1; j <= n; j++) {
        if (w[j] > w[i]) {
          numbBigger++; 
        }
      }
      for (int j = 2; j <= i - 1; j++) {
        if (w[j] < w[i]) {
          ans += 1LL * numbSmaller[j] * numbBigger;
        }
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}