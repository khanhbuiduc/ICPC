#include <iostream> 
#include <math.h>
struct element {
  long long lazy; 
  long long value; 
};
element it[4 * 50005]; 
int n, numQuery; 

void lazyUpdate(int index, int L, int R) {
  if (L < R) {
    long long lazyValue = it[index].lazy; 
    it[2 * index].lazy += lazyValue; 
    it[2 * index].value += lazyValue; 
    it[2 * index + 1].lazy += lazyValue; 
    it[2 * index + 1].value += lazyValue; 
    it[index].lazy = 0; 
  }  
}

void update(int index, int L, int R, int l, int r, long long val) {
  if (l > R || L > r) {
    return; 
  }
  if (l <= L && R <= r) {
    it[index].lazy += val;
    it[index].value += val;
    lazyUpdate(index, L, R);
    return;   
  }
  lazyUpdate(index, L, R);
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r, val); 
  update(2 * index + 1, mid + 1, R, l, r, val);
  it[index].value = std::max(it[2 * index].value, it[2 * index + 1].value);  
}

long long getMax(int index, int L, int R, int l, int r) {
  lazyUpdate(index, L, R); 
  if (l > R || L > r) {
    return -1; 
  }  
  if (l <= L && R <= r) {
    return it[index].value; 
  }
  int mid = (L + R) / 2; 
  long long maxLeft = getMax(2 * index, L, mid, l, r);
  long long maxRight = getMax(2 * index + 1, mid + 1, R, l, r); 
  return std::max(maxLeft, maxRight); 
}

int main () {
  std::cin >> n >> numQuery;
  for (int query = 1; query <= numQuery; query++) {
    int type;
    std::cin >> type; 
    if (type == 0) {
      int l, r, value;
      std::cin >> l >> r >> value;
      update(1, 1, n, l, r, value);
    }
    else {
      int l, r;
      std::cin >> l >> r; 
      std::cout << getMax(1, 1, n, l, r) << std::endl; 
    }
  }
  return 0; 
}