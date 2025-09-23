#include <iostream>
#include <math.h> 
int a[200005], p[200005]; 
struct itnode {
  int lazy = 0;
  int maxValue = 0; 
};
itnode it[4 * 200005]; 
int n; 
void lazyUpdate(int index, int L, int R) {
  if (it[index].lazy > 0 && L < R) {
    it[2 * index].lazy += it[index].lazy; 
    it[2 * index].maxValue -= it[index].lazy; 
    it[2 * index + 1].lazy += it[index].lazy;
    it[2 * index + 1].maxValue -= it[index].lazy;
  }
  it[index].lazy = 0; 
}
 
void create(int index, int L, int R, int position, int value) {
  lazyUpdate(index, L, R); 
  if (position < L || position > R) {
    return; 
  }
  if (L == R) {
    it[index].maxValue = value; 
    return; 
  }
  int mid = (L + R) / 2;
  create(2 * index, L, mid, position, value);
  create(2 * index + 1, mid + 1, R, position, value);
  it[index].maxValue = std::max(it[2 * index].maxValue, it[2 * index + 1].maxValue);  
}
 
void update(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return; 
  }  
  if (l <= L && R <= r) {
    it[index].lazy++; 
    it[index].maxValue -= it[index].lazy; 
    lazyUpdate(index, L, R); 
    return; 
  }
  lazyUpdate(index, L, R); 
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r);
  update(2 * index + 1, mid + 1, R, l, r); 
  it[index].maxValue = std::max(it[2 * index].maxValue, it[2 * index + 1].maxValue); 
}          
 
int query(int index, int L, int R, int position) {
  lazyUpdate(index, L, R); 
  if (L == R) {
    return L; 
  }
  int mid = (L + R) / 2; 
  int leftPosition = it[2 * index].maxValue; 
  if (leftPosition >= position) {
    return query(2 * index, L, mid, position); 
  }
  else {
    return query(2 * index + 1, mid + 1, R, position); 
  }
}
 
int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i]; 
  }
  for (int i = 1; i <= n; i++) {
    create(1, 1, n, i, i); 
  }
  for (int i = 1; i <= n; i++) {
    int position = query(1, 1, n, p[i]); 
    std::cout << a[position] << ' ';
    create(1, 1, n, position, 0);  
    update(1, 1, n, position + 1, n);
  }
  return 0; 
}