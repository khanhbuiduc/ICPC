#include <bits/stdc++.h> 

using namespace std;
int numTest; 
int n, m; 

int main () {
  freopen("SPC6.INP", "r", stdin);
  freopen("SPC6.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    cout << (__gcd(n, m) == 1 ? "CORRECT" : "INCORRECT") << endl;
  } 
  return 0; 
}