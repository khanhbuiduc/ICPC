#include <iostream> 
#include <vector>
#include <algorithm>
const int BLOCK = 447;  
struct question {
  int l, r, id; 
  bool operator < (const question &other) {
    if (l / BLOCK != other.l / BLOCK) {
      return (l < other.l); 
    }  
    return (r < other.r); 
  }
};
std::vector <question> listQuery; 
int n, numQuery; 
int a[200005]; 
long long ans[200005]; 
int cnt[1000005];
long long sum = 0LL; 

void increase(const int &numb, const int &value) {
  sum = sum + 2LL * numb * value + value;   
}

void decrease(const int &numb, const int &value) {
  sum = sum - 2LL * numb * value + value; 
}

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin >> n >> numQuery; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int query = 0; query < numQuery; query++) {
    int l, r; 
    std::cin >> l >> r; 
    listQuery.push_back((question) {l, r, query}); 
  }
  std::sort(listQuery.begin(), listQuery.end()); 
  int L = listQuery[0].l;
  int R = listQuery[0].r; 
  for (int i = L; i <= R; i++) {
    increase(cnt[a[i]], a[i]);
    cnt[a[i]]++; 
  }
  ans[listQuery[0].id] = sum; 
  for (int query = 1; query < numQuery; query++) {
    while (L > listQuery[query].l) {
      L--;
      increase(cnt[a[L]], a[L]);
      cnt[a[L]]++;       
    }
    while (L < listQuery[query].l) {
      decrease(cnt[a[L]], a[L]); 
      cnt[a[L]]--; 
      L++;                            
    }
    while (R < listQuery[query].r) {
      R++;
      increase(cnt[a[R]], a[R]); 
      cnt[a[R]]++; 
    }
    while (R > listQuery[query].r) {
      decrease(cnt[a[R]], a[R]);
      cnt[a[R]]--; 
      R--; 
    }
    ans[listQuery[query].id] = sum; 
  }
  for (int query = 0; query < numQuery; query++) {
    std::cout << ans[query] << std::endl;
  }
  return 0;
}