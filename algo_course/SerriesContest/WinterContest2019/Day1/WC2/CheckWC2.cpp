#include <bits/stdc++.h>
using namespace std;
int T;
vector <int> save;
vector <vector <pair <int, int> > > ss; 

bool Check(int v, const vector <pair <int, int> > &vv) {
  vector <int> x(v + 1, 0);
  vector <int> y(v + 1, 0);
  if (v != (int) vv.size()) {
    return false; 
  } 
  for (int i = 0; i < v; i++) {
    if (x[vv[i].first] != 0 || y[vv[i].second] != 0) {
      return false;  
    }
    x[vv[i].first] = 1;
    y[vv[i].second] = 1; 
  }
  return true; 
}

int main () {
  freopen("WC2.INP", "r", stdin);
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    save.push_back(n); 
  }
  freopen("WC2.OUT", "r", stdin);
  for (int t = 1; t <= T; t++) {
    vector <pair <int, int> > v;
    for (int i = 0; i < save[t - 1]; i++) {
      int x, y; 
      cin >> x >> y;
      v.push_back(make_pair(x, y)); 
    }
    ss.push_back(v);
    string s;
    cin >> s;
    if (s != "##########") {
      cout << "Wrong Answer" << endl;
      cout << "0.0" << endl;
      return 0; 
    }                
  }
  bool check = true;
  for (int t = 0; t < T; t++) {
    if (Check(save[t], ss[t]) == false) {
      cout << "Wrong Answer" << endl;
      cout << "0.0";
      check = false;
      break; 
    }
  }
  if (check == true) {
    cout << "Correct" << endl; 
    cout << "1.0" << endl; 
  }
  return 0; 
}