#include <iostream> 
#include <algorithm>
#include <vector> 
int n; 
long long L, R; 
int a[100005]; 

long long calc(long long X, const std::vector <long long> &a, const std::vector <long long> &b) {
  long long ret = 0LL; 
  long long sum = 0LL; 
  for (int i = 0; i < (int) b.size(); i++) {
    sum += b[i]; 
    int lo = 0;     
    int hi = (int) a.size() - 1; 
    int position = -1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (a[mid] <= X - sum) {
        position = mid;
        lo = mid + 1;   
      } 
      else {
        hi = mid - 1; 
      }
    }
    ret += position + 1; 
  }
  return ret; 
}

long long solve(int l, int r) {
  if (l == r) {
    if (L <= a[l] && a[l] <= R) {
      return 1LL; 
    }
    else {
      return 0LL; 
    }
  }
  long long ret = 0LL;
  int mid = (l + r) / 2;  
  ret += solve(l, mid);
  ret += solve(mid + 1, r); 
  long long sum = 0LL; 
  std::vector <long long> prefixSum; 
  for (int i = mid; i >= l; i--) {
    sum += a[i]; 
    prefixSum.push_back(sum); 
  }
  std::sort(prefixSum.begin(), prefixSum.end()); 
  std::vector <long long> suffixElement; 
  for (int i = mid + 1; i <= r; i++) {
    suffixElement.push_back(a[i]); 
  }
  ret += calc(R, prefixSum, suffixElement) - calc(L - 1, prefixSum, suffixElement); 
  return ret; 
}

int main () {  
  std::cin >> n >> L >> R;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  std::cout << solve(1, n); 
  return 0; 
}