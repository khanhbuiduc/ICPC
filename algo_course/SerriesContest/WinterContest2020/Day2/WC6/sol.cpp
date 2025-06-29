#include <iostream>
#include <string>
#include <fstream> 
#include <algorithm>

using namespace std;
int numTest; 
string s;
long long pos; 

int main () {
  freopen("WC6.INP", "r", stdin);
  freopen("WC6.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s >> pos;
    pos--;     
    string rev_s = s; 
    reverse(rev_s.begin(), rev_s.end()); 
    string st = s; 
    st += rev_s; 
    int len = (int) st.size();
    pos %= len; 
    cout << st[pos] << endl;
  }   
  return 0; 
}