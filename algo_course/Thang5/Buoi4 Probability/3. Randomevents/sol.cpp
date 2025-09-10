#include <iostream>
#include <vector>
#include <iomanip>
struct element {
  int position; 
  double probability; 
}; 
int numTest; 
std::vector <element> listElement; 
int n, numQuery; 
int a[100005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    listElement.clear();
    std::cin >> n >> numQuery; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 1; i <= numQuery; i++) {
      int position;
      double probability; 
      std::cin >> position >> probability; 
      listElement.push_back((element) {position, probability}); 
    }
    int shouldChangePosition = n + 1;
    for (int i = n; i >= 1; i--) {
      if (a[i] != i) {
        shouldChangePosition = i;
        break; 
      }
    } 
    double ans = 1.0;
    for (int i = 0; i < (int) listElement.size(); i++) {
      element e = listElement[i]; 
      if (e.position >= shouldChangePosition) {
        ans *= (1.0 - e.probability); 
      }
    } 
    std::cout << std::fixed << std::setprecision(12) << (shouldChangePosition == n + 1 ? 1.00000000000 : (1.0 - ans)) << std::endl; 
  }
  return 0; 
}