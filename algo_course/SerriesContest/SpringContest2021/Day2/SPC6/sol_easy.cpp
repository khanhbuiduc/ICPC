#include <iostream>
#include <string>
#include <vector>

using namespace std;
int numTest;
vector <string> a;
int n, m;

int main () {
  freopen("SPC6.INP", "r", stdin);
  freopen("SPC6.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    a.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      a.push_back(s);
    }
    cout << n + m - 3 << endl;
  }
  return 0;
}