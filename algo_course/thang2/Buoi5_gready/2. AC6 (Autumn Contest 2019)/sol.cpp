#include <iostream> 
#include <algorithm>
#include <utility>
#include <cstring>   
int n, k, numTest; 
std::pair <int, int> a[55]; 
int color[55]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].second >> a[i].first; 
    }
    std::sort(a + 1, a + n + 1); 
    int ans = 0; 
    int numCandies = 0; 
    std::memset(color, 0, sizeof(color)); 
    for (int i = n; i >= 1; i--) {
      if (numCandies == 2 * k) {
        break; 
      }
      if (color[a[i].second] < k) {
        color[a[i].second]++; 
        ans += a[i].first; 
        numCandies++; 
      }
    }
    if (numCandies != 2 * k) {
      std::cout << -1 << std::endl; 
    }
    else {
      std::cout << ans << std::endl; 
    }
  }
  return 0; 
}