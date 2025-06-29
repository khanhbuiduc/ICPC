#include <bits/stdc++.h>

using namespace std;
int numTest;

int main () {
  freopen("AC6.INP", "r", stdin);
  freopen("AC6.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, n;
    cin >> a >> b >> n;
    int gcd = __gcd(a, b);
    if (n % gcd != 0) {
      cout << -1 << endl;
      continue;
    }
    a /= gcd;
    b /= gcd;
    n /= gcd;
    if (a > b) {
      swap(a, b);
    }             
    bool flag = false;
    for (int i = n / b; i >= 0; i--) {
      int remain = n - i * b;
      if (remain % a == 0) {
        int x = remain / a;
        flag = true;
        cout << x + i << endl;
        break;
      }
    }
    if (flag == false) {
      cout << -1 << endl;        
    }
  }
  return 0; 
}










































































        