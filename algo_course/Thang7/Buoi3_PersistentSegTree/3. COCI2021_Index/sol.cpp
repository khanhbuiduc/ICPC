#include <iostream>
#include <vector> 
struct itnode {
  int totalPapers; 
  itnode *left, *right; 
};
std::vector <itnode *> version;
int p[200005];
int n, numQueries;
itnode *createNode() {
  itnode *ret = new itnode();
  ret->totalPapers = 0;
  ret->left = NULL;
  ret->right = NULL; 
  return ret; 
}  
void build(itnode *&root, int L, int R) {
  if (L == R) {
    root = createNode();
    return;
  }
  root = createNode(); 
  int mid = (L + R) / 2; 
  build(root->left, L, mid);
  build(root->right, mid + 1, R); 
}
void update(itnode *&root, int L, int R, int position) {
  if (L == R) {
    itnode *ret = createNode();
    *ret = *root;
    ret->totalPapers++;
    root = ret; 
    return; 
  }
  itnode *ret = createNode(); 
  *ret = *root; 
  int mid = (L + R) / 2; 
  if (position <= mid) {
    update(ret->left, L, mid, position); 
  }
  else {
    update(ret->right, mid + 1, R, position); 
  }
  ret->totalPapers = ret->left->totalPapers + ret->right->totalPapers; 
  root = ret; 
}
int get(itnode *rootLow, itnode *rootHigh, int L, int R, int more) {
  if (L == R) {
    return L; 
  }
  int mid = (L + R) / 2; 
  int numbLarge = rootHigh->right->totalPapers - rootLow->right->totalPapers; 
  if (numbLarge + more >= mid + 1) {
    return get(rootLow->right, rootHigh->right, mid + 1, R, more); 
  }
  return get(rootLow->left, rootHigh->left, L, mid, more + numbLarge); 
}

int main () {
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  itnode *root; 
  build(root, 1, 200000);         
  version.push_back(root);
  for (int i = 1; i <= n; i++) {
    update(root, 1, 200000, p[i]);
    version.push_back(root);   
  } 
  for (int query = 1; query <= numQueries; query++) {
    int L, R; 
    std::cin >> L >> R;
    int ans = get(version[L - 1], version[R], 1, 200000, 0);
    std::cout << ans << std::endl;   
  }
  return 0; 
}