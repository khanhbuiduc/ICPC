#include <iostream>
#include <set>
#include <string> 
struct node {
  node *child[26]; 
  std::set <int> setPositions;
  std::set <int> setEnds;  
};
int n, numQueries; 
std::string a[100005];
node *root; 

node *createNode() {
  node *ret = new node(); 
  for (int c = 0; c < 26; c++) {
    ret->child[c] = NULL; 
  }
  ret->setPositions.insert(n + 1);
  return ret;
}

void addString(node *root, const std::string &s, int position) {
  node *p = root; 
  for (int i = 0; i < (int) s.size(); i++) {
    int c = s[i] - 'a'; 
    if (p->child[c] == NULL) {
      p->child[c] = createNode();
    }
    p = p->child[c]; 
    p->setPositions.insert(position); 
  }
  p->setEnds.insert(position); 
}

void removeString(node *root, const std::string &s, int position) {
  node *p = root;
  for (int i = 0; i < (int) s.size(); i++) {
    int c = s[i] - 'a'; 
    p = p->child[c]; 
    std::set <int>::iterator it = p->setPositions.find(position); 
    p->setPositions.erase(it); 
  }
  std::set <int>::iterator it = p->setEnds.find(position); 
  p->setEnds.erase(it); 
}

bool foundSubarray(node *root, int L, int R, const std::string &s) {
  node *p = root;
  for (int i = 0; i < (int) s.size(); i++) {
    int c = s[i] - 'a'; 
    if (p->child[c] == NULL) {
      return false; 
    }
    p = p->child[c]; 
    std::set <int>::iterator it = p->setPositions.lower_bound(L); 
    if (*it > R) {
      return false; 
    }
    it = p->setEnds.lower_bound(L); 
    if (it != p->setEnds.end() && *it <= R) {
      return true; 
    }
  }
  return false;   
}

bool foundPrefix(node *root, int L, int R, const std::string &s) {
  node *p = root; 
  for (int i = 0; i < (int) s.size(); i++) {
    int c = s[i] - 'a'; 
    if (p->child[c] == NULL) {
      return false; 
    }                                    
    p = p->child[c]; 
    std::set <int>::iterator it = p->setPositions.lower_bound(L); 
    if (*it > R) {
      return false; 
    }
  }
  return true; 
}
              
int main () {
  std::cin >> n;
  root = createNode(); 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    addString(root, a[i], i);  
  }
  std::cin >> numQueries; 
  for (int query = 1; query <= numQueries; query++) {
    int type;
    std::cin >> type;
    if (type == 1) {
      int position;
      std::string s;
      std::cin >> position >> s;
      removeString(root, a[position], position);
      a[position] = s; 
      addString(root, a[position], position);    
    }
    else if (type == 2) {
      int L, R;
      std::string s;
      std::cin >> L >> R >> s;
      bool found = foundSubarray(root, L, R, s);
      std::cout << (found == true ? 'Y' : 'N') << std::endl; 
    }
    else {
      int L, R;
      std::string s;
      std::cin >> L >> R >> s;
      bool found = foundPrefix(root, L, R, s); 
      std::cout << (found == true ? 'Y' : 'N') << std::endl; 
    }
  }
  return 0; 
}