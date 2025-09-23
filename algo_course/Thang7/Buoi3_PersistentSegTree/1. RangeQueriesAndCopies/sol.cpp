#include <iostream> 
#include <vector>
int n, numQueries; 
int a[200005]; 
struct itnode {
  itnode *left, *right; 
  long long sum; 
};
std::vector <itnode*> version; 

itnode *createNode() {
  itnode *ret = new itnode(); 
  ret->left = NULL;
  ret->right = NULL; 
  ret->sum = 0LL; 
  return ret; 
}                          

void build(itnode *&root, int L, int R) {
  root = createNode();
  if (L == R) { 
    root->sum = a[L]; 
    return; 
  }
  int mid = (L + R) / 2; 
  build(root->left, L, mid);
  build(root->right, mid + 1, R); 
  root->sum = root->left->sum + root->right->sum; 
}

long long get(itnode *root, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return 0LL;
  }
  if (l <= L && R <= r) {
    return root->sum; 
  }
  int mid = (L + R) / 2; 
  long long leftValue = get(root->left, L, mid, l, r); 
  long long rightValue = get(root->right, mid + 1, R, l, r); 
  return leftValue + rightValue; 
}

void update(itnode *&root, int L, int R, int position, const long long &value) {
  if (L == R) {
    root = createNode();
    root->sum = value;
    return;             
  }  
  itnode *tmp = createNode(); 
  *tmp = *root;  
  int mid = (L + R) / 2; 
  if (position <= mid) {
    update(tmp->left, L, mid, position, value);  
  }
  else {
    update(tmp->right, mid + 1, R, position, value); 
  }
  tmp->sum = tmp->left->sum + tmp->right->sum; 
  root = tmp; 
}

int main () {
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  itnode *version0; 
  version.push_back(version0); 
  build(version[0], 1, n);
  for (int query = 1; query <= numQueries; query++) {
    int type, ver; 
    std::cin >> type >> ver; 
    if (type == 3) {
      itnode *newver = createNode(); 
      *newver = *version[ver - 1]; 
      version.push_back(newver); 
    }
    else if (type == 2) {
      int l, r; 
      std::cin >> l >> r; 
      std::cout << get(version[ver - 1], 1, n, l, r) << std::endl;
    }
    else {
      int position;
      long long value;
      std::cin >> position >> value;
      update(version[ver - 1], 1, n, position, value);  
    }
  }
  return 0; 
}