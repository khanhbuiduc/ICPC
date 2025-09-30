#include <iostream> 
int numTest; 
int n;
int a[100005]; 
bool chosen[100005]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      chosen[i] = false; 
    }
    long long ans = 0LL; 
    for (int b = 29; b >= 0; b--) {
      int cnt = 0; 
      for (int i = 1; i <= n; i++) {
        if (chosen[i] == false && (a[i] & (1 << b)) > 0) {
          cnt++; 
          chosen[i] = true; 
        }
      }
      ans += 1LL * cnt * (cnt - 1) / 2; 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}