#include <iostream>
#include <cstring> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>
std::pair <int, int> a[200005];
int numTest;
int n; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].first; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].second; 
    }
    std::sort(a + 1, a + n + 1); 
    long long ans = 0LL;                             
    for (int aj = 1; aj <= (int) std::sqrt(2 * n); aj++) {
      std::vector <int> cnt; 
      cnt.resize(n + 1, 0); 
      for (int i = 1; i <= n; i++) {
        int bj = aj * a[i].first - a[i].second;
        if (1 <= bj && bj <= n) {
          ans += cnt[bj];
        }
        if (a[i].first == aj) {
          cnt[a[i].second]++;
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
} 
