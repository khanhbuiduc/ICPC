#include <iostream> 
#include <fstream> 
#include <algorithm>
#include <math.h>
#include <vector> 
int n, k, s, t;
std::vector <int> g; 
int cost[200005], fuel[200005]; 

int main () {
  std::cin >> n >> k >> s >> t;
  for (int i = 1; i <= n; i++) {
    std::cin >> cost[i] >> fuel[i]; 
  }
  g.push_back(0);
  g.push_back(s); 
  for (int i = 1; i <= k; i++) {
    int position;
    std::cin >> position;
    g.push_back(position); 
  }
  std::sort(g.begin(), g.end()); 
  int lo = 1; 
  int hi = 1000000000; 
  int minFuel = -1; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int L = mid;
    int sumTime = 0; 
    bool found = true; 
    for (int i = 1; i < (int) g.size(); i++) {
      int d = g[i] - g[i - 1]; 
      int y = std::min(L - d, d); 
      if (y < 0) {
        found = false;
        break;   
      }
      sumTime += 2 * d - y; 
    }
    if (found == true) {
      if (sumTime <= t) {
        minFuel = L; 
        hi = mid - 1; 
      }  
      else {
        lo = mid + 1; 
      }
    }
    else {
      lo = mid + 1; 
    }
  }
  if (minFuel == -1) {
    std::cout << -1; 
  }
  else {
    int ans = 1000000007; 
    for (int i = 1; i <= n; i++) {
      if (fuel[i] >= minFuel) {
        ans = std::min(ans, cost[i]); 
      }
    }
    std::cout << (ans == 1000000007 ? -1 : ans); 
  }
  return 0; 
}