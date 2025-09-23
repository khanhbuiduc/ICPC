#include <iostream> 
#include <string> 
int n;
std::string res = "", maxS = "";
std::string a[100005]; 
int pos = -1;  
int numbPrints = 0; 
struct node {
  node *child[26]; 
  bool type = false;              
  int numbWords = 0; 
};
node *createNode() {
  node *ret = new node(); 
  ret->numbWords = 0; 
  ret->type = false; 
  for (int c = 0; c < 26; c++) {
    ret->child[c] = NULL; 
  }
  return ret; 
}
                                                                    
void addWord(node *root, const std::string &s, bool type) {
  node *p = root; 
  for (int i = 0; i < (int) s.size(); i++) {
    if (p->child[s[i] - 'a'] == NULL) {
      p->child[s[i] - 'a'] = createNode(); 
    }
    p = p->child[s[i] - 'a'];
    p->type = type;  
  }
  p->numbWords++; 
}

void dfs(node *root) { 
  for (int i = 1; i <= root->numbWords; i++) {
    res += 'P'; 
    numbPrints++; 
    if (numbPrints == n) {
      std::cout << (int) res.size() << std::endl;
      std::cout << res; 
      exit(0); 
    }
  }
  char chLast = '.'; 
  for (int c = 0; c < 26; c++) {
    if (root->child[c] == NULL) {
      continue; 
    }
    if (root->child[c]->type == true) {
      chLast = (char) (c + 'a'); 
      break; 
    } 
  }                                
  for (int c = 0; c < 26; c++) {
    if (root->child[c] == NULL || (char) (c + 'a')  == chLast) {
      continue;   
    }                                                                        
    res += (char) (c + 'a'); 
    dfs(root->child[c]); 
    res += '-'; 
  }  
  if (chLast != '.') {
    res += chLast; 
    dfs(root->child[chLast - 'a']); 
  }
}
        
int main () {
  node *root = createNode(); 
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::string s;
    std::cin >> s;
    a[i] = s; 
    if ((int) maxS.size() < (int) s.size()) {
      maxS = s; 
      pos = i;  
    }                 
  }
  for (int i = 1; i <= n; i++) {
    if (i != pos) {
      addWord(root, a[i], false); 
    }
  }
  addWord(root, a[pos], true); 
  dfs(root); 
  return 0; 
}