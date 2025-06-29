#include <iostream> 
struct athletic {
  int r1, r2, r3, r4, r5; 
};

bool compare(const athletic &a, const athletic &b) {
  int cnt = 0; 
  if (a.r1 < b.r1) {
    cnt++; 
  }
  if (a.r2 < b.r2) {
    cnt++; 
  }
  if (a.r3 < b.r3) {
    cnt++; 
  }
  if (a.r4 < b.r4) {
    cnt++; 
  }
  if (a.r5 < b.r5) {
    cnt++; 
  }
  return (cnt >= 3); 
}
athletic a[50005]; 
int n, numTest; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].r1 >> a[i].r2 >> a[i].r3 >> a[i].r4 >> a[i].r5; 
    }
    int best = 1; 
    for (int i = 2; i <= n; i++) {
      if (compare(a[i], a[best]) == true) {
        best = i;   
      }
    }
    bool ans = true; 
    for (int i = 1; i <= n; i++) {
      if (i != best && compare(a[best], a[i]) == false) {
        ans = false;
        break;     
      }
    }
    std::cout << (ans == true ? best : -1) << std::endl; 
  } 
  return 0; 
}