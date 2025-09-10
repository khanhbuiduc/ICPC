#include <iostream> 
#include <functional>
#include <queue>
#include <utility> 
#include <algorithm>
#include <vector> 
int numTest; 
int n, k; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::priority_queue <int, std::vector <int>, std::greater <int> > pq; 
    std::cin >> n >> k; 
    std::vector <std::pair <int, int> > a; 
    for (int i = 1; i <= n; i++) {
      int l, r;
      std::cin >> l >> r; 
      a.push_back(std::make_pair(l, r)); 
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
      pq.push(a[i].second); 
    }
    int ans = 0; 
    if (pq.top() >= a[k - 1].first) {
      ans = pq.top() - a[k - 1].first + 1; 
    } 
    for (int i = k; i < n; i++) {
      pq.pop(); 
      pq.push(a[i].second); 
      if (pq.top() >= a[i].first) {
        ans = std::max(ans, pq.top() - a[i].first + 1); 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}