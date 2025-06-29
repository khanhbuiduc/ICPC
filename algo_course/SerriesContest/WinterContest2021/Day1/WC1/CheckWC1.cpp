#include <iostream> 
#include <vector>
#include <set>
#include <fstream> 
#include <cassert>

using namespace std; 

struct elementInput {
  int n, m;
  vector <vector <int> > arr; 
};

vector <elementInput> inp;

struct element {
  int x1, y1, x2, y2, color; 
};

struct elementOutput {
  vector <element> arr;   
};
vector <elementOutput> out; 
int numTest; 

bool check(const elementInput &inp, const elementOutput &out) {
  vector <vector <int> > a = inp.arr;
  int n = inp.n;
  int m = inp.m; 
  vector <element> result = out.arr;
  assert((int) result.size() <= 2000 && (int) result.size() >= 1);
  vector <vector <int> > grid;
  grid.resize(n);
  for (int i = 0; i < n; i++) {
    grid[i].resize(m, 0); 
  }  
  set <int> setColor;
  for (int i = 0; i < (int) result.size(); i++) {
    int x1 = result[i].x1; 
    int y1 = result[i].y1;
    int x2 = result[i].x2;
    int y2 = result[i].y2;
    int color = result[i].color;
    assert(1 <= color && color <= 2000); 
    setColor.insert(color); 
    for (int x = x1; x <= x2; x++) {
      for (int y = y1; y <= y2; y++) {
        grid[x][y] = color; 
      }
    }
  }
  if ((int) setColor.size() != (int) result.size()) {
    return false; 
  }
  return a == grid; 
}

int main () {
  freopen("WC1.INP", "r", stdin); 
  cin.clear();
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > a; 
    a.resize(n); 
    for (int i = 0; i < n; i++) {
      a[i].resize(m); 
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j]; 
      }
    }
    inp.push_back((elementInput) {n, m, a}); 
  }
  freopen("WC1.OUT", "r", stdin); 
  cin.clear();
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int k;
    cin >> k;
    vector <element> save;  
    for (int i = 1; i <= k; i++) {
      int x1, y1, x2, y2, color;
      cin >> x1 >> y1 >> x2 >> y2 >> color;
      x1--;
      y1--;
      x2--;
      y2--;
      save.push_back((element) {x1, y1, x2, y2, color}); 
    }
    out.push_back((elementOutput) {save}); 
  }
  for (int i = 0; i < numTest; i++) {
    if (check(inp[i], out[i]) == false) {
      cout << "WRONG ANSWER" << endl;
      cout << 0.0 << endl;
      return 0;   
    }
  }
  cout << "CORRECT" << endl; 
  cout << 1.0 << endl;
  return 0; 
}