#include <iostream>
#include <random>
#include <vector>
int n, x;
bool used[1000005];
std::default_random_engine engine;
std::uniform_int_distribution <long long> dist(1, 1000000);     
int ans[100005];
int main () {
  std::cin >> n >> x; 
  int steps = 0;
  while (steps < 500) {
    for (int i = 1; i <= 1000000; i++) {
      used[i] = false; 
    }
    int sumXor = 0;
    for (int i = 1; i < n; i++) {
      int value = dist(engine); 
      while (used[value] == true) {
        value = dist(engine); 
      }
      ans[i] = value; 
      sumXor ^= value; 
      used[value] = true; 
    }
    int rest = x ^ sumXor;
    if (rest <= 1000000 && used[rest] == false) {
      ans[n] = rest;
      std::cout << "YES" << std::endl;
      for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << ' ';
      }  
      exit(0);
    } 
    steps++;    
  }
  std::cout << "NO";   
  return 0; 
}