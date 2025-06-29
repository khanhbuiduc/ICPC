#include <iostream> 
#include <string> 
#include <fstream> 

using namespace std;
int numTest; 
string chemistry;

int main () {
  freopen("WC5.INP", "r", stdin);
  freopen("WC5.OUT", "w", stdout); 
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> chemistry; 
    for (int i = 0; i < (int) chemistry.size() - 1; i++) {
      cout << chemistry[i]; 
    }
    char oper;
    cin >> oper; 
    cin >> chemistry; 
    for (int i = 0; i < (int) chemistry.size() - 2; i++) {
      cout << chemistry[i];
    }
    cout << endl; 
  }
  return 0; 
}