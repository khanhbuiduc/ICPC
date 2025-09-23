#include <iostream> 
#include <math.h> 
#include <string> 
struct element {
  int freeOpen;
  int freeClose; 
  int maxCorrect; 
};
element it[4 * 1000005]; 
std::string brackets;
int numQuery; 

void build(int index, int L, int R) {
  if (L == R) {
    if (brackets[L] == '(') {
      it[index] = (element) {1, 0, 0};   
    }
    else {
      it[index] = (element) {0, 1, 0}; 
    }
    return; 
  }
  int mid = (L + R) / 2;
  build(2 * index, L, mid);
  build(2 * index + 1, mid + 1, R); 
  element ret; 
  ret.freeOpen = it[2 * index].freeOpen + it[2 * index + 1].freeOpen - std::min(it[2 * index].freeOpen, it[2 * index + 1].freeClose); 
  ret.freeClose = it[2 * index].freeClose + it[2 * index + 1].freeClose - std::min(it[2 * index].freeOpen, it[2 * index + 1].freeClose); 
  ret.maxCorrect = it[2 * index].maxCorrect + it[2 * index + 1].maxCorrect + 2 * std::min(it[2 * index].freeOpen, it[2 * index + 1].freeClose); 
  it[index] = ret; 
}

element get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return (element) {0, 0, 0}; 
  }
  if (l <= L && R <= r) {
    return it[index]; 
  }
  int mid = (L + R) / 2; 
  element eLeft = get(2 * index, L, mid, l, r); 
  element eRight = get(2 * index + 1, mid + 1, R, l, r); 
  element ret; 
  ret.freeOpen = eLeft.freeOpen + eRight.freeOpen - std::min(eLeft.freeOpen, eRight.freeClose); 
  ret.freeClose = eLeft.freeClose + eRight.freeClose - std::min(eLeft.freeOpen, eRight.freeClose); 
  ret.maxCorrect = eLeft.maxCorrect + eRight.maxCorrect + 2 * std::min(eLeft.freeOpen, eRight.freeClose); 
  return ret; 
}

int main () {
  std::cin >> brackets; 
  int n = (int) brackets.size(); 
  build(1, 0, n - 1); 
  std::cin >> numQuery; 
  for (int query = 1; query <= numQuery; query++) {
    int l, r; 
    std::cin >> l >> r;
    element ans = get(1, 0, n - 1, l - 1, r - 1);
    std::cout << ans.maxCorrect << std::endl; 
  }
  return 0; 
}