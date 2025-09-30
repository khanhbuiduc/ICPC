#include <iostream> 
#include <math.h> 
#include <map> 
long long cost[35]; 
int numTest; 
int maxNumbCoins[100005]; 
long long X; 
std::map <long long, int> cnt; 
void init() {
  for (int value = 0; value <= 100000; value++) {
    maxNumbCoins[value] = -1; 
  }
  cost[1] = 2; 
  cost[2] = 3; 
  cost[3] = 5;                         
  for (int i = 4; i <= 34; i++) {
    cost[i] = cost[i - 1] + cost[i - 2] + cost[i - 3]; 
  }
  for (int mask = 0; mask < (1 << 17); mask++) {
    long long totalCost = 0LL; 
    for (int i = 0; i < 17; i++) {
      if ((mask & (1 << i)) > 0) {
        totalCost += cost[i + 1]; 
      }
    }
    maxNumbCoins[totalCost] = std::max(maxNumbCoins[totalCost], (int) __builtin_popcount(mask)); 
  }
  for (int mask = 0; mask < (1 << 17); mask++) {
    long long totalCost = 0LL; 
    for (int i = 0; i < 17; i++) {
      if ((mask & (1 << i)) > 0) {
        totalCost += cost[i + 18]; 
      }
    }
    cnt[totalCost] = std::max(cnt[totalCost], (int) __builtin_popcount(mask)); 
  }
}

int main () {
  init();
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> X; 
    int ans = -1; 
    for (std::map <long long, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
      if (it->first <= X) {
        if (X - it->first <= 100000 && maxNumbCoins[X - it->first] != -1) {
          ans = std::max(ans, it->second + maxNumbCoins[X - it->first]); 
        }  
      }
      else {
        break; 
      } 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}