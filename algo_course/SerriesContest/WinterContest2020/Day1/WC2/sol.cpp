#include <iostream> 
#include <vector> 
#include <fstream>

using namespace std;
int numTest; 
vector <int> funnyMoment; 
int n; 

int main () {
  freopen("WC2.INP", "r", stdin);
  freopen("WC2.OUT", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n; 
    funnyMoment.clear();
    funnyMoment.push_back(0);  
    for (int i = 1; i <= n; i++) {
      int funnyTime; 
      cin >> funnyTime; 
      funnyMoment.push_back(funnyTime); 
    }
    funnyMoment.push_back(90); 
    bool found = false; 
    for (int i = 1; i <= n + 1; i++) {
      if (funnyMoment[i] - funnyMoment[i - 1] > 15) {
        cout << funnyMoment[i - 1] + 15;
        found = true;  
        break; 
      }
    }
    if (found == false) {
      cout << 90; 
    }
    cout << endl; 
  }
  return 0; 
}