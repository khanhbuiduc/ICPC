#include <iostream> 
#include <string> 
std::string core, pattern; 
long long hashCore[100005];
long long pw250[100005];  
int n; 
int ans = -1; 
int times; 

int main () {
  getline(std::cin, core);
  n = (int) core.size(); 
  hashCore[0] = 0LL;
  pw250[0] = 1LL; 
  for (int i = 1; i <= n; i++) {
    hashCore[i] = hashCore[i - 1] * 250LL + (int) core[i - 1];
    pw250[i] = pw250[i - 1] * 250LL;  
  } 
  getline(std::cin, pattern); 
  std::cin >> times; 
  int lo = 1; 
  int hi = (int) pattern.size(); 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    long long hashValue = 0LL; 
    for (int i = 0; i < mid; i++) {
      hashValue = hashValue * 250LL + (int) pattern[i]; 
    }
    int cnt = 0; 
    for (int l = 1; l + mid - 1 <= n; l++) {
      int r = l + mid - 1; 
      long long hash = hashCore[r] - hashCore[l - 1] * pw250[mid]; 
      if (hash == hashValue) {
        cnt++; 
      }
    }
    if (cnt >= times) {
      ans = mid; 
      lo = mid + 1; 
    }
    else {
      hi = mid - 1; 
    }
  }
  if (ans == -1) {
    std::cout << "IMPOSSIBLE"; 
  }
  else {
    for (int i = 0; i < ans; i++) {
      std::cout << pattern[i];
    }
  }
  return 0; 
}