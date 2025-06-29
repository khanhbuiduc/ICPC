#include <iostream> 
#include <vector> 
#include <fstream>
int numTest; 
std::vector <int> funnyMoment; 
int n; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    funnyMoment.clear();
    funnyMoment.push_back(0);  
    for (int i = 1; i <= n; i++) {
      int funnyTime; 
      std::cin >> funnyTime; 
      funnyMoment.push_back(funnyTime); 
    }
    funnyMoment.push_back(90); 
    bool found = false; 
    for (int i = 1; i <= n + 1; i++) {
      if (funnyMoment[i] - funnyMoment[i - 1] > 15) {
        std::cout << funnyMoment[i - 1] + 15;
        found = true;  
        break; 
      }
    }
    if (found == false) {
      std::cout << 90; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}