#include <iostream> 
#include <math.h>
struct node {
  node *child[2]; 
};
node *root;

node *createNode() {
  node *ret = new node();
  ret->child[0] = NULL;
  ret->child[1] = NULL; 
  return ret;
}

void add(int value) {
  node *p = root;
  for (int i = 30; i >= 0; i--) {
    int bit = (value & (1 << i)) > 0; 
    if (p->child[bit] == NULL) {
      p->child[bit] = createNode(); 
    }
    p = p->child[bit]; 
  }
}
 
int getMax(int value) {
  node *p = root;
  int ret = 0; 
  for (int i = 30; i >= 0; i--) {
    int bit = (value & (1 << i)) > 0; 
    if (p->child[!bit] != NULL) {
      ret += (1 << i);
      p = p->child[!bit];   
    }
    else {
      p = p->child[bit]; 
    }
  }
  return ret; 
}
 
int main () {
  root = createNode();
  int sum = 0;
  add(0);
  int n; 
  std::cin >> n; 
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    sum ^= x; 
    ans = std::max(ans, getMax(sum));
    add(sum); 
  }
  std::cout << ans;
  return 0;
}