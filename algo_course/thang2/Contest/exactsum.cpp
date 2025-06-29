#include <iostream> 
#include <algorithm> 
int a[10005]; 
int n; 
int total; 

int binarySearch(int l, int r, int value) {
  int lo = l; 
  int hi = r; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    if (a[mid] == value) {
      return mid; 
    }
    else if (a[mid] > value) {
      hi = mid - 1; 
    }
    else {
      lo = mid + 1; 
    }
  }
  return -1; 
}

int main () {
  while (std::cin >> n) {
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::sort(a + 1, a + n + 1); 
    std::cin >> total; 
    for (int i = 1; i <= n; i++) {
      int rest = total - a[i];
      int pos = binarySearch(1, i - 1, rest);
      if (pos != -1) {
        std::cout << "Peter should buy books whose prices are ";
        std::cout << a[pos] << " and " << a[i] << "." << std::endl; 
        std::cout << std::endl; 
        break; 
      } 
    }
  }
  return 0; 
}