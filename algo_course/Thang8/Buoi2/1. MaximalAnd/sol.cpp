#include <iostream>
int numTest;
int n, k;
int a[200005];  

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int ans = 0; 
    for (int bit = 30; bit >= 0; bit--) {
      int cnt = 0; 
      for (int i = 1; i <= n; i++) {
        if ((a[i] & (1 << bit)) == 0) {
          cnt++;   
        }
      }
      if (k >= cnt) {
        ans += (1 << bit); 
        k -= cnt; 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}