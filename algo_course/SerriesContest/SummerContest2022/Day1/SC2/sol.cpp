#include <bits/stdc++.h> 

using namespace std;

int numTest; 
long long k; 
int main () {
  freopen("SC2.INP", "r", stdin); 
  freopen("SC2.OUT", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> k; 
    long long lo = 1; 
    long long hi = 2000000000000000007LL; 
    long long ans = -1; 
    while (lo <= hi) {
      long long mid = (lo + hi) / 2; 
      long long total = mid / 3 + mid / 5 + mid / 7 - mid / 15 - mid / 35 - mid / 21 + mid / 105; 
      if (total >= k) {
        ans = mid; 
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}