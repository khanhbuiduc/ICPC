#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <random>
#include <map>                     
std::vector <long long> valueC; 
int n, k; 
long long sum = 0LL; 

int main () {
  std::cin >> n >> k;
  std::default_random_engine engine;
  std::uniform_int_distribution <long long> dist(1, 16e10);
  valueC.resize(k - 1);
  for (int i = 0; i < k - 1; i++) {
    valueC[i] = dist(engine); 
    sum += valueC[i];
  }   
  valueC.push_back(-sum); 
  int ans = 0; 
  std::map <long long, int> pos; 
  sum = 0LL;
  pos[0] = 0; 
  for (int i = 0; i < n; i++) {
    int candy;
    std::cin >> candy; 
    sum += valueC[candy - 1];
    if (pos.find(sum) != pos.end()) {
      int lastPos = pos[sum]; 
      ans = std::max(ans, i - lastPos + 1); 
    } 
    else {
      pos[sum] = i + 1;
    }
  }
  std::cout << ans;
  return 0; 
}