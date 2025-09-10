#include <iostream>
#include <algorithm> 
int numTest; 
int a[200005]; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::sort(a + 1, a + n + 1); 
    if (a[1] != 1) {
      std::cout << "NO" << std::endl;
      continue; 
    }
    long long sum = 1LL; 
    bool check = true; 
    for (int i = 2; i <= n; i++) {
      if (a[i] > sum) {
        check = false;
        break; 
      }
      sum += a[i]; 
    }
    if (check == true) {
      std::cout << "YES" << std::endl; 
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0; 
}