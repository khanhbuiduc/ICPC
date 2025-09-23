#include <iostream>
#include <vector>
int a[30005];
int n, numQueries;  
std::vector <int> it[4 * 30005]; 

std::vector <int> mergeArray(const std::vector <int> &a1, const std::vector <int> &a2) {
  std::vector <int> ret; 
  int p1 = 0; 
  int p2 = 0; 
  while (p1 < (int) a1.size() && p2 < (int) a2.size()) {
    if (a1[p1] < a2[p2]) {
      ret.push_back(a1[p1]); 
      p1++; 
    }
    else {
      ret.push_back(a2[p2]); 
      p2++; 
    }
  }
  while (p1 < (int) a1.size()) {
    ret.push_back(a1[p1]);
    p1++;
  }
  while (p2 < (int) a2.size()) {
    ret.push_back(a2[p2]); 
    p2++; 
  }
  return ret; 
}

void build(int index, int L, int R) {
  if (L == R) {
    it[index].push_back(a[L]); 
    return; 
  }
  int mid = (L + R) / 2; 
  build(2 * index, L, mid); 
  build(2 * index + 1, mid + 1, R); 
  it[index] = mergeArray(it[2 * index], it[2 * index + 1]); 
}

int get(int index, int L, int R, int l, int r, int k) {
  if (l > R || L > r) {
    return 0; 
  }
  if (l <= L && R <= r) {
    int sz = (int) it[index].size(); 
    int lo = 0; 
    int hi = sz - 1; 
    int position = sz;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (it[index][mid] > k) {
        position = mid; 
        hi = mid - 1; 
      } 
      else {
        lo = mid + 1; 
      }
    }
    return sz - position; 
  }
  int mid = (L + R) / 2;
  int numbLeft = get(2 * index, L, mid, l, r, k);
  int numbRight = get(2 * index + 1, mid + 1, R, l, r, k);                                   
  return numbLeft + numbRight; 
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  build(1, 1, n);
  std::cin >> numQueries;
  for (int query = 1; query <= numQueries; query++) {
    int l, r, k; 
    std::cin >> l >> r >> k; 
    std::cout << get(1, 1, n, l, r, k) << std::endl;
  } 
  return 0; 
}