#include <iostream>
#include <cstring> 
int n, m, k, numTest;
int boy[200005];
int girl[200005];
int cntBoys[200005];
int cntGirls[200005];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::memset(cntBoys, 0, sizeof(cntBoys));
    std::memset(cntGirls, 0, sizeof(cntGirls));
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
      std::cin >> boy[i];
    }
    for (int i = 1; i <= k; i++) {
      std::cin >> girl[i];
    }
    long long ans = 0LL; 
    for (int i = 1; i <= k; i++) {
      ans += i - 1 - cntBoys[boy[i]] - cntGirls[girl[i]]; 
      cntBoys[boy[i]]++;
      cntGirls[girl[i]]++; 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}