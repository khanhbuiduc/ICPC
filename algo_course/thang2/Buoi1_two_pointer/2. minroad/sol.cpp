#include <iostream> 
#include <vector>
#include <algorithm>
#include <math.h> 
const int inf = 1000000007; 

struct element {
  int x, type;
  bool operator < (const element &other) const {
    return (x < other.x);
  } 
};
std::vector <element> a; 
int n, type1, type2; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> n >> type1 >> type2; 
  for (int i = 1; i <= n; i++) {
    element e;
    std::cin >> e.x >> e.type; 
    a.push_back(e);
  }
  std::sort(a.begin(), a.end()); 
  int cntFirst = 0, cntSecond = 0; 
  int l = 0;
  int ans = inf;  
  for (int i = 0; i < n; i++) {
    if (a[i].type == 1) {
      cntFirst++; 
    }
    else {
      cntSecond++;
    }
    while (cntFirst >= type1 && cntSecond >= type2) {
      ans = std::min(ans, a[i].x - a[l].x); 
      if (a[l].type == 1) { 
        cntFirst--; 
      }
      else {
        cntSecond--; 
      }
      l++;
    }
  }
  std::cout << (ans == inf ? -1 : ans);
  return 0; 
}
