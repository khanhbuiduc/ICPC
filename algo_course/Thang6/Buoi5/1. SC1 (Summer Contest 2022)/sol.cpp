#include <iostream>
#include <string>
#include <cstring>
#include <utility> 
int numTest; 
std::string name[4]; 
int cnt[4]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> name[0] >> name[1] >> name[2] >> name[3]; 
    std::memset(cnt, 0, sizeof(cnt)); 
    for (int i = 0; i < 52; i++) {
      std::pair <std::string, std::string> card;
      std::cin >> card.first >> card.second;  
      if (card.first == "2") {
        cnt[i % 4]++; 
      }
    }
    bool found = false; 
    for (int i = 0; i < 4; i++) {
      if (cnt[i] == 4) {
        std::cout << name[i] << " is absolute winner" << std::endl; 
        found = true; 
        break; 
      }
    } 
    if (found ==  false) {
      std::cout << "The game has started" << std::endl; 
    } 
  }
  return 0; 
}