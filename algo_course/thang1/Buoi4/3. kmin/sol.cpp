#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
struct element {
  int p1, p2, value; 
  bool operator < (const element &other) const {
    return value > other.value; 
  }
};

std::priority_queue <element> pq; 
int n, m, k; 
std::vector <int> a, b; 

int main () {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int x; 
    std::cin >> x; 
    a.push_back(x); 
  }
  for (int i = 1; i <= m; i++) {
    int x; 
    std::cin >> x; 
    b.push_back(x); 
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  for (int i = 0; i < m; i++) {
    pq.push((element) {0, i, a[0] + b[i]});
  }
  for (int i = 1; i <= k; i++) {
    element pqTop = pq.top(); 
    pq.pop(); 
    std::cout << pqTop.value << std::endl; 
    if (pqTop.p1 < n - 1) {
      pq.push((element) {pqTop.p1 + 1, pqTop.p2, a[pqTop.p1 + 1] + b[pqTop.p2]});
    }
  }
  return 0; 
}