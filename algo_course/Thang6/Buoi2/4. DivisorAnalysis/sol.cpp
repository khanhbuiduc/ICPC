#include <iostream> 
#include <utility> 
#include <vector> 
const long long mod = 1000000007LL;
std::vector <std::pair <long long, long long> > a;
int n;  

long long fastPow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL; 
  }
  long long ret = fastPow(x, n / 2); 
  (ret *= ret) %= mod; 
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

long long sum(const long long &x) {
  long long ret = x; 
  ret *= (x + 1); 
  ret /= 2; 
  ret %= (mod - 1); 
  return ret; 
}

int main () {
  std::cin >> n;
  std::vector <long long> prefix(n + 2, 1LL), suffix(n + 2, 1LL); 
  for (int i = 0; i < n; i++) {
    long long x, k;
    std::cin >> x >> k; 
    a.push_back(std::make_pair(x, k)); 
  }
  for (int i = 1; i <= n; i++) {
    prefix[i] = (prefix[i - 1] * (a[i - 1].second + 1)) % (mod - 1); 
  }
  for (int i = n; i >= 1; i--) {
    suffix[i] = (suffix[i + 1] * (a[i - 1].second + 1)) % (mod - 1); 
  }
  long long ans1 = 1LL; 
  for (int i = 0; i < n; i++) {
    (ans1 *= (a[i].second + 1)) %= mod;   
  }
  std::cout << ans1 << ' '; 
  long long ans2 = 1LL; 
  for (int i = 0; i < n; i++) {
    (ans2 *= (fastPow(a[i].first, a[i].second + 1) - 1 + mod) % mod) %= mod; 
    (ans2 *= fastPow(a[i].first - 1, mod - 2)) %= mod; 
  }
  std::cout << ans2 << ' '; 
  long long ans3 = 1LL; 
  for (int i = 1; i <= n; i++) {
    long long power = prefix[i - 1];
    (power *= suffix[i + 1]) %= (mod - 1);
    (power *= sum(a[i - 1].second)) %= (mod - 1);
    (ans3 *= fastPow(a[i - 1].first, power)) %= mod;  
  }
  std::cout << ans3; 
  return 0; 
}