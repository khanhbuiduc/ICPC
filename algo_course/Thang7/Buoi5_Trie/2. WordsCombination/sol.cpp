#include <iostream> 
#include <string> 
#include <vector> 
struct trieNode {
  std::vector <trieNode *> child; 
  bool isEnd; 
};
 
trieNode *createNode() {
  trieNode *ret = new trieNode(); 
  ret->child.resize(26); 
  for (int c = 0; c < 26; c++) {
    ret->child[c] = NULL; 
  }
  ret->isEnd = false; 
  return ret; 
}
std::string pattern;
trieNode *root;  
void addString(const std::string &s) {
  trieNode *p = root; 
  for (int i = 0; i < (int) s.size(); i++) {
    if (p->child[s[i] - 'a'] == NULL) {
      p->child[s[i] - 'a'] = createNode(); 
    }
    p = p->child[s[i] - 'a']; 
  }
  p->isEnd = true; 
}
std::vector <std::vector <int> > have; 
int f[5005]; 
const int mod = 1000000007; 
 
int main () {
  std::cin >> pattern;
  int n = (int) pattern.size(); 
  root = createNode(); 
  int k;
  std::cin >> k;
  for (int i = 1; i <= k; i++) {
    std::string word;
    std::cin >> word; 
    addString(word); 
  }
  have.resize(n); 
  for (int i = 0; i < n; i++) {
    trieNode *p = root; 
    for (int j = i; j < n; j++) {
      if (p->child[pattern[j] - 'a'] == NULL) {
        break; 
      }
      p = p->child[pattern[j] - 'a'];
      if (p->isEnd == true) {
        have[i].push_back(j); 
      }  
    }
  }
  f[0] = 1; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) have[i].size(); j++) {
      (f[have[i][j] + 1] += f[i]) %= mod; 
    }
  }
  std::cout << f[n]; 
  return 0; 
}
