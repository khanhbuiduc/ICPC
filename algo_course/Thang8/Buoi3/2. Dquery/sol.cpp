#include <iostream> 
#include <algorithm> 
#include <vector> 
const int BLOCK = 173; 
struct question {
  int l, r, id; 
  bool operator < (const question &other) {
    if (l / BLOCK != other.l / BLOCK) {
      return l < other.l; 
    }
    return r < other.r; 
  }
};
std::vector <question> listQuery; 
int ans[200005]; 
int cnt[1000005]; 
int a[30005];
int n, numQuery; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  std::cin >> numQuery;
  for (int query = 0; query < numQuery; query++) {
    int l, r;
    std::cin >> l >> r;
    listQuery.push_back((question) {l, r, query});   
  }
  std::sort(listQuery.begin(), listQuery.end());
  int L = listQuery[0].l;
  int R = listQuery[0].r;
  int numDiff = 0; 
  for (int i = L; i <= R; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] == 1) {
      numDiff++; 
    }  
    ans[listQuery[0].id] = numDiff; 
  } 
  for (int query = 1; query < numQuery; query++) {
    while (L > listQuery[query].l) {
      L--; 
      cnt[a[L]]++; 
      if (cnt[a[L]] == 1) {
        numDiff++; 
      }
    }
    while (L < listQuery[query].l) {
      cnt[a[L]]--;
      if (cnt[a[L]] == 0) {
        numDiff--; 
      }
      L++; 
    }
    while (R < listQuery[query].r) {
      R++;
      cnt[a[R]]++; 
      if (cnt[a[R]] == 1) {
        numDiff++; 
      }
    }   
    while (R > listQuery[query].r) {
      cnt[a[R]]--; 
      if (cnt[a[R]] == 0) {
        numDiff--; 
      }
      R--; 
    }
    ans[listQuery[query].id] = numDiff; 
  }
  for (int query = 0; query < numQuery; query++) {
    std::cout << ans[query] << std::endl; 
  }
  return 0; 
}