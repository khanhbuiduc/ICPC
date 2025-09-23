#include <iostream> 
#include <vector> 
#include <cstring> 
struct query {
  int l, r; 
};
std::vector <query> listQuery;
bool it[4 * 100005]; 
int numTest; 
int n, m;

void lazy(int index) {
  if (it[index] == true) {
    it[2 * index] = true;
    it[2 * index + 1] = true; 
  }
} 

bool get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return true; 
  }    
  if (L < R) {
    lazy(index);
  } 
  if (l <= L && R <= r) {
    return it[index]; 
  }
  int mid = (L + R) / 2; 
  bool coverLeft = get(2 * index, L, mid, l, r);
  bool coverRight = get(2 * index + 1, mid + 1, R, l, r); 
  if (coverLeft == true && coverRight == true) {
    return true; 
  }
  return false; 
}

void update(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return; 
  }
  if (it[index] == true) {
    if (L < R) {
      lazy(index); 
    }
    return; 
  }
  if (l <= L && R <= r) {
    it[index] = true; 
    if (L < R) {
      lazy(index); 
    }
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r);
  update(2 * index + 1, mid + 1, R, l, r); 
  if (it[2 * index] == true && it[2 * index + 1] == true) {
    it[index] = true; 
  }
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::memset(it, false, sizeof(it)); 
    listQuery.clear();
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      int l, r;
      std::cin >> l >> r; 
      listQuery.push_back((query) {l, r}); 
    }
    int ans = 0; 
    for (int i = (int) listQuery.size() - 1; i >= 0; i--) {
      int l = listQuery[i].l;
      int r = listQuery[i].r;
      bool isCovered = get(1, 1, m, l, r);
      if (isCovered == false) {
        ans++; 
      }     
      update(1, 1, m, l, r); 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}