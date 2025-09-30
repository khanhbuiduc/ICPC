#include <iostream> 
#include <set> 
#include <vector> 
int n, m; 
int a[35]; 
std::set <int> minSum; 
std::vector <int> a1, a2; 

void process(const std::vector <int> &a) {
  int sz = (int) a.size(); 
  for (int mask = 0; mask < (1 << sz); mask++) {
    int sum = 0; 
    for (int i = 0; i < sz; i++) {
      if ((mask & (1 << i)) > 0) {
        (sum += a[i]) %= m; 
      }  
    }
    minSum.insert(sum); 
  }
}

void solve(const std::vector <int> &a) {
  int sz = (int) a.size(); 
  int ans = 0; 
  for (int mask = 0; mask < (1 << sz); mask++) {
    int sum = 0; 
    for (int i = 0; i < sz; i++) {
      if ((mask & (1 << i)) > 0) {
        (sum += a[i]) %= m; 
      }
    }
    int rest = m - 1 - sum; 
    std::set <int>::iterator it = minSum.upper_bound(rest); 
    if (it != minSum.begin()) {
      it--;
      ans = std::max(ans, sum + (*it));   
    }
    it = minSum.end(); 
    it--; 
    ans = std::max(ans, (sum + (*it)) % m); 
  }
  std::cout << ans;
}

int main () {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i] %= m;  
  }
  int half = n / 2;
  for (int i = 0; i < half; i++) {
    a1.push_back(a[i]); 
  }          
  for (int i = half; i < n; i++) {
    a2.push_back(a[i]); 
  }
  process(a1);
  solve(a2);  
  return 0; 
}