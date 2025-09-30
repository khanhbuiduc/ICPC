#include <iostream> 
#include <ctime>
#include <vector>
#include <cstdlib> 
#include <random>
#include <algorithm> 
int n; 
std::vector <int> a;
std::vector <int> p;  
std::vector <int> ans; 

int main () {
  std::srand(19260817); 
  std::cin >> n;
  a.resize(n); 
  p.resize(n); 
  ans.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
    p[i] = i; 
  }
  for (int steps = 1; steps <= 70; steps++) {
    std::random_shuffle(p.begin(), p.end());
    int gcd1 = a[p[0]], gcd2 = -1;
    ans[p[0]] = 1; 
    for (int i = 1; i < n; i++) {
      if (std::__gcd(gcd1, a[p[i]]) < gcd1) {
        gcd1 = std::__gcd(gcd1, a[p[i]]);
        ans[p[i]] = 1;  
      }
      else {
        if (gcd2 == -1) {
          gcd2 = a[p[i]]; 
        }
        else {
          gcd2 = std::__gcd(gcd2, a[p[i]]); 
        }
        ans[p[i]] = 2; 
      }  
    }
    if (gcd1 == 1 && gcd2 == 1) {
      std::cout << "YES" << std::endl; 
      for (int i = 0; i < n; i++) {
        std::cout << ans[i] << ' '; 
      }
      return 0; 
    } 
  }
  std::cout << "NO"; 
  return 0; 
}