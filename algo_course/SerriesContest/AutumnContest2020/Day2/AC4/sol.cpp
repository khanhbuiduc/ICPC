#include <bits/stdc++.h> 

using namespace std; 
string s[7] = {"Do", "Re", "Mi", "Fa", "Son", "La", "Si"};

int main () {
  freopen("AC4.INP", "r", stdin);
  freopen("AC4.OUT", "w", stdout); 
  int test; 
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    int n, m;
    cin >> n >> m; 
    vector <int> a; 
    for (int i = 1; i <= n; i++) {
      string node; 
      cin >> node; 
      for (int j = 0; j < 7; j++) {
        if (node == s[j]) {
          a.push_back(j); 
        }
      }
    }
    int res = 0; 
    for (int i = 1; i < n - 1; i++) {
      if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
        res++; 
      }  
      else if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
        res++; 
      }
    }
    if (res >= m) {
      cout << "YES" << endl; 
    }
    else {
      cout << "NO" << endl; 
    }
  }
  return 0; 
}