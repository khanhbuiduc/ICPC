#include <iostream>
#include <math.h>  
int a[100005]; 
int n, numTest; 
struct element {
  int maxLeft, maxRight, maxSum; 
  element(int _maxLeft, int _maxRight, int _maxSum) {
    maxLeft = _maxLeft;
    maxRight = _maxRight; 
    maxSum = _maxSum; 
  }
};
element calc(int l, int r) {
  element ret(0, 0, 0); 
  if (l == r) {
    ret.maxLeft = a[l];
    ret.maxRight = a[l]; 
    ret.maxSum = a[l];
  }
  else {
    int sum = 0; 
    int maxi = -1000000007;
    for (int i = l; i <= r; i++) {
      sum += a[i]; 
      maxi = std::max(maxi, sum); 
    } 
    ret.maxLeft = maxi;
    sum = 0;
    maxi = -1000000007;  
    for (int i = r; i >= l; i--) {
      sum += a[i]; 
      maxi = std::max(maxi, sum); 
    }
    ret.maxRight = maxi; 
    int mid = (l + r) / 2; 
    element leftElement = calc(l, mid); 
    element rightElement = calc(mid + 1, r); 
    ret.maxSum = std::max(leftElement.maxSum, std::max(rightElement.maxSum, leftElement.maxRight + rightElement.maxLeft)); 
  }
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int subsequence = 0; 
    int maxElement = -10005; 
    for (int i = 1; i <= n; i++) {
      if (a[i] >= 0) {
        subsequence += a[i]; 
      }
      maxElement = std::max(maxElement, a[i]); 
    }
    if (maxElement < 0) {
      subsequence = maxElement; 
    }
    std::cout << calc(1, n).maxSum << ' ' << subsequence << std::endl; 
  }
  return 0; 
}