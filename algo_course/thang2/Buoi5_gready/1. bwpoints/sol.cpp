#include <iostream> 
#include <algorithm> 
#include <math.h> 
#include <vector>
struct point {
  int distance;
  int color; 
  bool operator < (const point &other) {
    return (distance < other.distance); 
  }
};                 
int n; 
std::vector <point> a; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    point element;
    std::cin >> element.distance;
    element.color = 0;
    a.push_back(element);   
  }
  for (int i = 1; i <= n; i++) {
    point element;
    std::cin >> element.distance;
    element.color = 1;
    a.push_back(element);   
  }
  std::sort(a.begin(), a.end()); 
  int ans = 0; 
  for (int i = 0; i < (int) a.size() - 1; i++) {
    if (a[i].color != a[i + 1].color) {
      ans++; 
      i++; 
    }
  }
  std::cout << ans; 
  return 0; 
}