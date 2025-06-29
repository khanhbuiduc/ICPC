#include <iostream> 
#include <fstream> 

using namespace std;
int numTest;
int n;
int a[1000005];      

int main () {
  freopen("WC6.INP", "r", stdin);
  freopen("WC6.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    long long suma1 = 0LL, suma2 = 0LL, sumb1 = 0LL, sumb2 = 0LL;
    for (int i = 1; i <= n; i++) {
      int x; 
      cin >> x;
      suma1 += x; 
      sumb1 += i;
      suma2 += 1LL * x * x; 
      sumb2 += 1LL * i * i; 
    }
    long long subtract = suma1 - sumb1; 
    long long add = (suma2 - sumb2) / (suma1 - sumb1);
    long long X = (subtract + add) / 2; 
    long long Y = (add - subtract) / 2;
    cout << X << ' ' << Y << endl; 
  }
  return 0; 
}