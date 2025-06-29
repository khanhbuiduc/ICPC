#include <iostream> 
#include <fstream> 

using namespace std; 
const int MAX_N = 200005; 
int a[MAX_N];
int n, numTest; 

int main () {
  freopen("WC5.INP", "r", stdin);
  freopen("WC5.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    long long sum = 0LL;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      sum += a[i]; 
    }
    sum *= sum; 
    for (int i = 1; i <= n; i++) {
      sum -= 1LL * a[i] * a[i];
    }
    cout << sum / 2 << endl;
  }
  return 0; 
}