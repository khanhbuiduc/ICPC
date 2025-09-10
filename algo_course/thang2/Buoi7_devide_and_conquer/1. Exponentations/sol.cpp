#include <iostream>
const long long mod = 1000000007LL;  
int numTest; 

long long power(int x, int n) {
  if (n == 0) {
    return 1LL; 
  }
  if (n % 2 == 1) {
    return (power(x, n - 1) * x) % mod; 
  }
  long long ret = power(x, n / 2); 
  return (ret * ret) % mod; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x, n;
    std::cin >> x >> n; 
    std::cout << power(x, n) << std::endl; 
  }
  return 0; 
}