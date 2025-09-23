#include <iostream> 
#include <math.h> 
const int inf = 1000000007; 
int a[200005]; 
int it[4 * 200005]; 
int n, numQueries;

void build(int index, int L, int R) {
  if (L == R) {
    it[index] = a[L]; 
    return; 
  }
  int mid = (L + R) / 2; 
  build(2 * index, L, mid); 
  build(2 * index + 1, mid + 1, R); 
  it[index] = std::min(it[2 * index], it[2 * index + 1]); 
} 

int get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return inf; 
  }
  if (l <= L && R <= r) {
    return it[index]; 
  }
  int mid = (L + R) / 2; 
  int vLeft = get(2 * index, L, mid, l, r); 
  int vRight = get(2 * index + 1, mid + 1, R, l, r); 
  return std::min(vLeft, vRight); 
}

int main () {
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  build(1, 1, n); 
  for (int query = 1; query <= numQueries; query++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << get(1, 1, n, l, r) << std::endl;   
  }
  return 0; 
}