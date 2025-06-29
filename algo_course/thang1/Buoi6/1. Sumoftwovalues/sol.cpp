#include <iostream>
#include <map>  
int n, x; 
std::map <int, int> position; 
 
int main () {
  std::cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    int value; 
    std::cin >> value;
    if (value < x) {
      if (position.find(x - value) != position.end()) {
        std::cout << position[x - value] << ' ' << i; 
        return 0; 
      }
      position[value] = i;
    }
  }
  std::cout << "IMPOSSIBLE";
  return 0;
}