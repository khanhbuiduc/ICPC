#include <iostream> 
#include <vector>
#include <algorithm> 
int n, m;
std::vector <int> jack, jill; 

int main () {
  while (true) {
    std::cin >> n >> m;
    if (n == 0 && m == 0) {
      break;
    }
    jack.clear();
    jill.clear(); 
    for (int i = 1; i <= n; i++) {
      int value;
      std::cin >> value;
      jack.push_back(value);
    }
    for (int i = 1; i <= m; i++) {
      int value;
      std::cin >> value;
      jill.push_back(value);
    }
    std::sort(jack.begin(), jack.end());
    std::sort(jill.begin(), jill.end());
    int ans = 0; 
    while (!jack.empty() && !jill.empty()) {
      while (!jack.empty() && !jill.empty() && jack.back() > jill.back()) {
        jack.pop_back();
      }
      while (!jack.empty() && !jill.empty() && jack.back() < jill.back()) {
        jill.pop_back();  
      }
      if (!jack.empty() && !jill.empty() && jack.back() == jill.back()) {
        ans++;
        jack.pop_back();
        jill.pop_back();
      }  
    }
    std::cout << ans << std::endl;
  }
  return 0;
}