#include <iostream> 
int numQuery, x, mex = 0; 
int cnt[400005]; 

int main () {
  std::cin >> numQuery >> x;
  for (int i = 1; i <= numQuery; i++) {
    int value;
    std::cin >> value;
    cnt[value % x]++;
    while (true) {
      if (cnt[mex % x] > 0) {
        cnt[mex % x]--; 
        mex++; 
      }
      else {
        break; 
      }
    }   
    std::cout << mex << std::endl; 
  }
  return 0; 
}