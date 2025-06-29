#include <iostream>
#include <stack> 
int n;
int a[1005];              

int main () {
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break; 
    }
    while (true) {
      std::cin >> a[1]; 
      if (a[1] == 0) {
        break; 
      }
      for (int i = 2; i <= n; i++) {
        std::cin >> a[i]; 
      }
      std::stack <int> mystack; 
      int currentTruck = 0; 
      for (int i = 1; i <= n; i++) {
        while (currentTruck < n && currentTruck != a[i]) {
          if (!mystack.empty() && mystack.top() == a[i]) {
            break;
          }
          currentTruck++;
          mystack.push(currentTruck);
        }
        if (mystack.top() == a[i]) {
          mystack.pop(); 
        }
      }                                      
      if (mystack.empty() == true) {
        std::cout << "Yes" << std::endl; 
      }      
      else {
        std::cout << "No" << std::endl;
      }
    }
    std::cout << std::endl; 
  } 
  return 0; 
}