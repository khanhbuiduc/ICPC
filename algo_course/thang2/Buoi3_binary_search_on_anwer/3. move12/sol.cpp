#include <iostream> 
#include <algorithm> 
#include <queue>
#include <vector>
#include <functional> 
#include <utility>
#include <math.h>  
struct police {
  int column; 
  int speed; 
};
police a[10005]; 
int n; 

bool check(std::vector <std::pair <int, int> > &a) {
  std::sort(a.begin(), a.end()); 
  std::priority_queue <int, std::vector <int>, std::greater <int> > pq; 
  int p = 0; 
  for (int column = 1; column <= n; column++) {
    while (!pq.empty()) {
      if (pq.top() < column) {
        pq.pop(); 
      }
      else {
        break; 
      }
    }
    while (p < n && a[p].first <= column) {
      pq.push(a[p].second); 
      p++; 
    }
    if (pq.empty() == true) {
      return false; 
    }
    else {
      pq.pop(); 
    }
  }
  return true; 
}

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].column >> a[i].speed; 
  }
  int lo = 0; 
  int hi = 100000007;
  int ans = -1;  
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    std::vector <std::pair <int, int> > segment; 
    for (int i = 1; i <= n; i++) {
      segment.push_back(std::make_pair(std::max(1, a[i].column - mid / a[i].speed), std::min(n, a[i].column + mid / a[i].speed))); 
    }
    if (check(segment) == true) {
      ans = mid;
      hi = mid - 1;   
    }
    else {
      lo = mid + 1; 
    }
  }
  std::cout << ans; 
  return 0; 
}