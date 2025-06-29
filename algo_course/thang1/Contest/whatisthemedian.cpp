#include <iostream> 
#include <queue> 
#include <vector>
#include <functional>
std::priority_queue <long long> small; 
std::priority_queue <long long, std::vector <long long>, std::greater <long long> > large; 
long long x; 

int main () {
  while (std::cin >> x) {     
    if ((int) small.size() == (int) large.size()) {
      if (large.empty() == true || x <= large.top()) {
        small.push(x);            
      }
      else {
        int value = large.top();
        large.pop();
        small.push(value);
        large.push(x);  
      }
      std::cout << small.top(); 
    }
    else {
      if (x >= small.top()) {
        large.push(x); 
      }
      else {
        int value = small.top();
        small.pop();
        large.push(value);
        small.push(x);  
      }
      std::cout << (small.top() + large.top()) / 2; 
    }
    std::cout << std::endl; 
  }
  return 0; 
} 