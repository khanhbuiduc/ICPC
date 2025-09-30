#include <iostream> 
#include <vector>
#include <map> 
int a[105]; 
int n; 
std::map <std::vector <int>, int> mapValue; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int firsthalf = 0; firsthalf < (1 << 15); firsthalf++) {
    std::vector <int> numbOnes; 
    for (int i = 1; i <= n; i++) {
      int cntOnes = 0; 
      for (int b = 0; b < 15; b++) {
        int oneValue = ((firsthalf & (1 << b)) > 0);
        int oneArray = ((a[i] & (1 << b)) > 0);
        if (oneValue != oneArray) {
          cntOnes++; 
        } 
      }
      numbOnes.push_back(cntOnes); 
    }
    mapValue[numbOnes] = firsthalf; 
  }
  for (int secondhalf = 0; secondhalf < (1 << 15); secondhalf++) {
    std::vector <int> numbOnes; 
    for (int i = 1; i <= n; i++) {
      int cntOnes = 0;
      for (int b = 0; b < 15; b++) {
        int oneValue = ((secondhalf & (1 << b)) > 0);
        int oneArray = ((a[i] & (1 << (b + 15))) > 0);
        if (oneValue != oneArray) {
          cntOnes++; 
        }
      }
      numbOnes.push_back(cntOnes); 
    }
    for (int totalOnes = 0; totalOnes <= 30; totalOnes++) {
      std::vector <int> restOnes; 
      bool check = true; 
      for (int i = 0; i < n; i++) {
        if (totalOnes - numbOnes[i] > 15) {
          check = false;
          break; 
        }
        restOnes.push_back(totalOnes - numbOnes[i]);  
      }
      if (check == true) {
        if (mapValue.find(restOnes) != mapValue.end()) {
          std::cout << (secondhalf << 15) + mapValue[restOnes]; 
          return 0; 
        }
      }  
    }
  }
  std::cout << -1;
  return 0; 
}