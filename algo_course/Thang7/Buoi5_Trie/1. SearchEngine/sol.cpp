#include <iostream> 
#include <math.h>
#include <string> 

struct node {
  node *child[26]; 
  int maxValue;  
};

node *root;            
int numQuery; 
int n; 

node *createNode() {
  node *ret = new node(); 
  for (int c = 0; c < 26; c++) {
    ret->child[c] = NULL; 
  }
  ret->maxValue = 0;
  return ret; 
}

void addNode(const std::string &s, const int &value) {
  node *p = root;
  for (int i = 0; i < (int) s.size(); i++) {
    int c = s[i] - 'a'; 
    if (p->child[c] == NULL) {
      p->child[c] = createNode(); 
    }
    p = p->child[c];
    p->maxValue = std::max(p->maxValue, value);  
  }                
}

int findMaxValue(const std::string &s) {
  node *p = root;
  int ret = 0;  
  for (int i = 0; i < (int) s.size(); i++) {
    int c = s[i] - 'a'; 
    if (p->child[c] == NULL) {
      return -1; 
    }
    p = p->child[c]; 
  }
  return p->maxValue; 
}

int main () {
  root = new node(); 
  std::cin >> n >> numQuery;
  for (int i = 1; i <= n; i++) {
    std::string s; 
    int value; 
    std::cin >> s >> value; 
    addNode(s, value); 
  }
  for (int query = 1; query <= numQuery; query++) {
    std::string s; 
    std::cin >> s;
    std::cout << findMaxValue(s) << std::endl; 
  }
  return 0; 
}