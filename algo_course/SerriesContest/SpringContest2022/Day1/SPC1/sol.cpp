#include <bits/stdc++.h> 

using namespace std;
int numTest; 
int numQuery; 
struct node {
  int countPrefix;
  node *child[10]; 
};

node *createNode() {
  node *ret = new node();
  ret->countPrefix = 0; 
  for (int dig = 0; dig <= 9; dig++) {
    ret->child[dig] = NULL; 
  }
  return ret; 
}

node *root; 

string convertToString(int value) {
  string res = "";
  while (value > 0) {
    int r = value % 10;
    res += (char) (r + '0'); 
    value /= 10; 
  }
  reverse(res.begin(), res.end()); 
  while ((int) res.size() < 10) {
    res = "0" + res; 
  }
  return res; 
}

void add(int value) {
  const string s = convertToString(value);
  node *p = root;
  for (int i = 0; i < (int) s.size(); i++) {
    int dig = s[i] - '0'; 
    if (p->child[dig] == NULL) {
      p->child[dig] = createNode(); 
    }
    p = p->child[dig];
    p->countPrefix++; 
  } 
}

int get(int order) {
  int res = 0; 
  node *p = root; 
  for (int i = 1; i <= 10; i++) {
    int totalNumb = 0;
    int nextDigit = 0;
    for (int dig = 0; dig <= 9; dig++) {
      if (p->child[dig] != NULL) {
        totalNumb += p->child[dig]->countPrefix; 
        if (totalNumb >= order) {
          nextDigit = dig; 
          break; 
        }
      }  
    }
    res = res * 10 + nextDigit; 
    p = p->child[nextDigit]; 
    totalNumb -= p->countPrefix; 
    order -= totalNumb; 
  }
  return res; 
}

int main () {
  freopen("SPC1.INP", "r", stdin);
  freopen("SPC1.OUT", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    root = createNode();
    cin >> numQuery;
    for (int i = 1; i <= numQuery; i++) {
      int type, value; 
      cin >> type >> value;
      if (type == 1) {
        add(value); 
      }
      else {
        cout << get(value) << endl; 
      } 
    } 
  }
  return 0; 
}