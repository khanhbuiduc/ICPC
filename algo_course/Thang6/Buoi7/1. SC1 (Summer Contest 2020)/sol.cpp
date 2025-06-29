#include <iostream>
#include <string> 
int numTest; 
std::string s; 
bool check(const std::string st) {
  for (int i = (int) st.size() - 1, j = (int) s.size() - 1; i >= 0; i--, j--) {
    if (st[i] != s[j]) {
      return false;
    }
  }
  return true; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    bool found = false; 
    std::string res = "NONE"; 
    std::cin >> s; 
    for (int i = 1; i <= 9; i++) {
      std::string name, st;
      std::cin >> name >> st; 
      if (found == false && check(st) == true) {
        found = true;
        res = name;   
      }
    }
    if (res[(int) res.size() - 1] == ':') {
      res = res.substr(0, (int) res.size() - 1); 
    }                                    
    std::cout << res << std::endl; 
  }
  return 0; 
}