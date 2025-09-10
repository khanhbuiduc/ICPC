#include <stdio.h>
#include <vector>
#include <algorithm>

bool binarySearch(const std::vector <long long> &a, int pos, long long price) {
  int l = 0;
  int r = pos;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == price) {
      return true;
    }
    else if (a[mid] < price) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return false;
}

void solve() {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    long long totalPrice;
    std::cin >> n >> totalPrice;      
    std::vector <long long> a;
    for (int i = 1; i <= n; i++) {
      long long val;
      std::cin >> val; 
      a.push_back(val);
    }
    std::sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      long long firstPrice = a[i];
      long long secondPrice = totalPrice - firstPrice;
      bool check = binarySearch(a, i - 1, secondPrice);
      if (check == true) {
        ans++;
      }
    }
    std::cout << ans << std::endl; 
  }
}

int main () {
  solve();
  return 0;
}