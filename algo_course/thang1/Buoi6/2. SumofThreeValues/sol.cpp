#include <iostream>
#include <map> 
int n, M;
int a[5005]; 
std::map <int, int> position;
 
int main () {
  std::cin >> n >> M;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  position[a[1]] = 1; 
  for (int i = 2; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int sum = a[i] + a[j];
      if (sum < M) {
        if (position.find(M - sum) != position.end()) {
          std::cout << position[M - sum] << ' ' << i << ' ' << j;
          return 0;
        }
      }
    }
    position[a[i]] = i;
  }
  std::cout << "IMPOSSIBLE";
  return 0;
}