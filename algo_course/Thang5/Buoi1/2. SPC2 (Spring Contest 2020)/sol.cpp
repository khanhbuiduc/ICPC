#include <iostream> 
#include <algorithm>
#include <math.h> 
int a[100005]; 
int numTest, n; 

int main () {
  std::cin >> numTest;   
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;  
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    long long deno = 0, nume = 1LL * n; 
    std::sort(a + 1, a + n + 1); 
    long long S = 0LL;
    for (int i = 1; i <= n; i++) {
      S += 1LL * a[i]; 
    }
    deno = S; 
    long long curSum = 0LL; 
    for (int i = 1; i <= n; i++) {
      curSum += 1LL * a[i]; 
      deno += 1LL * S; 
      deno -= 2LL * curSum; 
      deno += 1LL * (2 * i - n) * a[i]; 
    }                                         
    long long gcd = std::__gcd(deno, nume); 
    deno /= gcd;
    nume /= gcd;
    std::cout << deno << ' ' << nume << std::endl; 
  }
  return 0; 
}