#include <iostream> 
#include <string>
#include <algorithm> 

std::string reorder(const std::string &s) {
  int n = (int) s.size(); 
  if (n % 2 == 1) {
    return s; 
  }
  std::string half1 = ""; 
  for (int i = 0; i < n / 2; i++) {
    half1 += s[i]; 
  }
  std::string half2 = ""; 
  for (int i = n / 2; i < n; i++) {
    half2 += s[i]; 
  }
  half1 = reorder(half1);
  half2 = reorder(half2); 
  std::string ret = ""; 
  if (half1 > half2) {
    std::swap(half1, half2); 
  }
  ret += half1;
  ret += half2;
  return ret; 
}

int main () {
  std::string s1, s2; 
  std::cin >> s1 >> s2; 
  if (reorder(s1) == reorder(s2)) {
    std::cout << "YES"; 
  }
  else {
    std::cout << "NO"; 
  }
  return 0; 
}