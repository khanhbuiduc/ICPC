#include <iostream>
#include <string>
#include <vector> 
std::string s[7] = {"Do", "Re", "Mi", "Fa", "Son", "La", "Si"};

int main () {
  int numTest; 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m;
    std::cin >> n >> m; 
    std::vector <int> a; 
    for (int i = 1; i <= n; i++) {
      std::string node; 
      std::cin >> node; 
      for (int j = 0; j < 7; j++) {
        if (node == s[j]) {
          a.push_back(j); 
        }
      }
    }
    int res = 0; 
    for (int i = 1; i < n - 1; i++) {
      if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
        res++; 
      }  
      else if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
        res++; 
      }
    }
    if (res >= m) {
      std::cout << "YES" << std::endl; 
    }
    else {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}