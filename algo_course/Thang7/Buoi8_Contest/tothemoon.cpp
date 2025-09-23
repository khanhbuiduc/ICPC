#include <iostream> 
#include <vector> 
struct itnode {
  long long lazy = 0LL;
  long long sum = 0LL; 
  itnode *nodeLeft, *nodeRight; 
};
std::vector <itnode *> version; 
long long a[100005]; 
int n, numQueries; 

itnode *createNode() {
  itnode *ret = new itnode(); 
  ret->lazy = 0LL;
  ret->sum = 0LL; 
  ret->nodeLeft = NULL;
  ret->nodeRight = NULL;
  return ret; 
}
  
void lazyUpdate(itnode *&root, int L, int R) {
  if (root->lazy != 0 && L < R) {
    int mid = (L + R) / 2; 
    itnode *newLeft, *newRight;
    newLeft = createNode();
    newRight = createNode();
    *newLeft = *root->nodeLeft;
    *newRight = *root->nodeRight;
    newLeft->lazy += root->lazy;
    newLeft->sum += 1LL * (mid - L + 1) * root->lazy;
    newRight->lazy += root->lazy;
    newRight->sum += 1LL * (R - mid) * root->lazy;
    root->nodeLeft = newLeft;
    root->nodeRight = newRight;  
  }
  root->lazy = 0LL; 
}

void build(itnode *&root, int L, int R) {
  root = createNode(); 
  if (L == R) {
    root->sum = a[L];
    return; 
  }
  int mid = (L + R) / 2; 
  build(root->nodeLeft, L, mid);
  build(root->nodeRight, mid + 1, R); 
  root->sum = root->nodeLeft->sum + root->nodeRight->sum; 
}

bool checkIntersect(int l1, int r1, int l2, int r2) {
  if (l1 > r2 || l2 > r1) {
    return false; 
  }
  return true; 
}

void update(itnode *&root, int L, int R, int l, int r, const long long &value) {
  itnode *newNode = createNode(); 
  *newNode = *root; 
  if (l <= L && R <= r) {
    newNode->lazy += value; 
    newNode->sum += 1LL * (R - L + 1) * value;
    lazyUpdate(newNode, L, R); 
    root = newNode;
    return; 
  }
  lazyUpdate(newNode, L, R); 
  int mid = (L + R) / 2; 
  if (checkIntersect(L, mid, l, r) == true) {
    update(newNode->nodeLeft, L, mid, l, r, value); 
  }
  if (checkIntersect(mid + 1, R, l, r) == true) {
    update(newNode->nodeRight, mid + 1, R, l, r, value); 
  }
  root = newNode; 
  root->sum = root->nodeLeft->sum + root->nodeRight->sum; 
}
 
long long get(itnode *&root, int L, int R, int l, int r) {
  lazyUpdate(root, L, R); 
  if (l <= L && R <= r) {
    return root->sum; 
  }
  if (l > R || L > r) {
    return 0LL; 
  }
  int mid = (L + R) / 2; 
  long long valueLeft = get(root->nodeLeft, L, mid, l, r); 
  long long valueRight = get(root->nodeRight, mid + 1, R, l, r); 
  return valueLeft + valueRight; 
}

int main () {
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  version.resize(numQueries + 1); 
  itnode *version0; 
  build(version0, 1, n); 
  int currentTime = 0; 
  version[currentTime] = version0;
  for (int query = 1; query <= numQueries; query++) {
    char type;
    std::cin >> type;
    if (type == 'B') {
      int backTime;
      std::cin >> backTime;
      currentTime = backTime;   
    }
    else if (type == 'C') {
      int l, r;
      long long value;
      std::cin >> l >> r >> value;
      itnode *newVersion = version[currentTime];   
      update(newVersion, 1, n, l, r, value);
      currentTime++;
      version[currentTime] = newVersion;  
    }
    else if (type == 'H') {
      int l, r, backTime; 
      std::cin >> l >> r >> backTime;
      std::cout << get(version[backTime], 1, n, l, r) << std::endl;  
    }
    else {
      int l, r;
      std::cin >> l >> r; 
      std::cout << get(version[currentTime], 1, n, l, r) << std::endl; 
    }
  }                           
  return 0; 
}