#include <bits/stdc++.h> 

using namespace std; 
int test; 

int main () {
  freopen("AC2.INP", "r", stdin);
  freopen("AC2.OUT", "w", stdout);
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    string s1, s2; 
    int numb1 = 0, numb2 = 0; 
    int a, b; 
    cin >> s1 >> s2; 
    cin >> a >> b; 
    int mini = min(a, b);
    string resname = ".", restime;  
    for (int i = 1; i <= a + b; i++) {
      string name, Time;
      cin >> name >> Time;
      if (s1 == name) {
        numb1++;                 
      } 
      else {
        numb2++;
      }
      if (max(numb1, numb2) > mini && resname == ".") {
        resname = name;
        restime = Time; 
      }
    }
    cout << resname << ' ' << restime << endl;  
  }
  return 0; 
}