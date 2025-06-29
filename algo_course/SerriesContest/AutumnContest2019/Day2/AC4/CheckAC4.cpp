#include <bits/stdc++.h> 

using namespace std; 
struct element {
  int row, col; 
  vector <string> s;
};
vector <pair <int, int> > inp;
vector <element> out; 
int T; 
char val[] = {'A', 'B', 'C'}; 
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

bool check(const pair <int, int> &in, const element &ou) {
  //cout << in.first << ' ' << in.second << endl; 
  //cout << "#################" << endl;
  /*for (int i = 0; i < ou.row; i++) {
    cout << ou.s[i] << endl; 
  } */
  if (ou.row > in.first || ou.col > in.first) {
    //cout << "dieu kien 1" << endl;
    return false; 
  }
  vector <string> a = ou.s; 
  for (int i = 0; i < ou.row; i++) {
    if ((int) a[i].size() != ou.col) {
      //cout << "dieu kien 2" << endl;
      return false; 
    }
  }
  for (int i = 0; i < ou.row; i++) {
    for (int j = 0; j < ou.col; j++) {
      if (a[i][j] != 'A' && a[i][j] != 'B' && a[i][j] != 'C') {
        //cout << "dieu kien 3" << endl;
        return false; 
      }
    }  
  }
  int cnt = 0; 
  for (int i = 0; i < ou.row; i++) {
    for (int j = 0; j < ou.col; j++) {
      if (a[i][j] == 'A') {
        for (int c = 0; c < 8; c++) {
          int x = i;
          int y = j; 
          bool flag = true; 
          for (int t = 0; t < 3; t++) {
            if (x < 0 || x >= ou.row || y < 0 || y >= ou.col) {
              flag = false; 
              break;
            }
            if (a[x][y] != val[t]) {
              flag = false; 
              break; 
            }  
            x += dx[c];
            y += dy[c]; 
          }
          if (flag == true) {
            cnt++; 
          }
        }
      }
    }
  }
  //cout << cnt << endl;
  return (cnt == in.second); 
}

int main () {
  freopen("AC4.INP", "r", stdin);
  cin.clear();
  cin >> T; 
  for (int t = 1; t <= T; t++) {
    int D, n;
    cin >> D >> n; 
    inp.push_back(make_pair(D, n)); 
  }
  freopen("AC4.OUT", "r", stdin); 
  cin.clear();                       
  for (int t = 1; t <= T; t++) {
    int row, col;
    cin >> row >> col; 
    vector <string> ss; 
    for (int i = 1; i <= row; i++) {
      string s;
      cin >> s; 
      ss.push_back(s); 
    }
    out.push_back((element) {row, col, ss}); 
  }
  //freopen("output.txt", "w", stdout);
  bool flag = true; 
  for (int t = 0; t < T; t++) {
    if (check(inp[t], out[t]) == false) {
      flag = false;
      break;    
    }
  }
  if (flag == true) {
    cout << "Correct" << endl; 
    cout << "1.0" << endl; 
  }
  else {
    cout << "Wrong Answer" << endl;
    cout << "0.0" << endl;  
  }
  return 0; 
}