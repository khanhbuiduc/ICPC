#include <iostream> 
#include <math.h> 
const int inf = -1000000007; 
struct node {
  int maxLeft, maxRight, maxSum, sum; 
};
node it[4 * 50005]; 
int a[50005];   
int n, numQueries;

node mergeNode(const node &nodeLeft, const node &nodeRight) {
  node ret;
  ret.maxLeft = std::max(nodeLeft.maxLeft, nodeLeft.sum + nodeRight.maxLeft);
  ret.maxRight = std::max(nodeRight.maxRight, nodeRight.sum + nodeLeft.maxRight);
  ret.sum = nodeLeft.sum + nodeRight.sum;
  ret.maxSum = std::max(nodeLeft.maxSum, std::max(nodeRight.maxSum, nodeLeft.maxRight + nodeRight.maxLeft));
  return ret;    
}

void build(int index, int L, int R) {
  if (L == R) {
    it[index] = (node) {a[L], a[L], a[L], a[L]}; 
    return; 
  }
  int mid = (L + R) / 2; 
  build(2 * index, L, mid);
  build(2 * index + 1, mid + 1, R);
  it[index] = mergeNode(it[2 * index], it[2 * index + 1]); 
} 

node get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return (node) {inf, inf, inf, 0}; 
  }
  if (l <= L && R <= r) {
    return it[index]; 
  }
  int mid = (L + R) / 2; 
  node nodeLeft = get(2 * index, L, mid, l, r);
  node nodeRight = get(2 * index + 1, mid + 1, R, l, r);
  return mergeNode(nodeLeft, nodeRight);   
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];            
  }
  build(1, 1, n);
  std::cin >> numQueries;
  for (int query = 1; query <= numQueries; query++) {
    int l, r; 
    std::cin >> l >> r; 
    std::cout << get(1, 1, n, l, r).maxSum << std::endl; 
  } 
  return 0; 
}