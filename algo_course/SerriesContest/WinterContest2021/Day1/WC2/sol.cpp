#include <iostream> 
#include <string> 
#include <fstream> 

using namespace std;
int numTest;
string N; 

int main () {
  freopen("WC2.INP", "r", stdin);
  freopen("WC2.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> N; 
    if (N == "1") {
      cout << "0" << endl; 
    }
    else {
      for (int i = (int) N.size() - 1; i >= 0; i--) {
        if (N[i] == '0') {
          N[i] = '9';
        }
        else {
          N[i] = (char) (N[i] - 1);
          break; 
        }
      }
      if (N[0] == '0') {
        for (int i = 1; i < (int) N.size(); i++) {
          cout << N[i];
        }
      }
      else {
        cout << N;
      }
      cout << endl;
    }
  }
  return 0; 
} 