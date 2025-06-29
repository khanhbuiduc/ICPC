#include <iostream>
#include <fstream>

using namespace std;
int numTest, N;

int main () {
  freopen("SPC2.INP", "r", stdin);
  freopen("SPC2.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cout << i << ' ' << 1 << endl;
    }
  }
  return 0;
}