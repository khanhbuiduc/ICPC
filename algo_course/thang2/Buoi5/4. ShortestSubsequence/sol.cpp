#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
const char ch[4] = {'A', 'C', 'G', 'T'}; 
std::string s; 
std::vector <int> position[4]; 
std::string ans = ""; 
 
int main () {
  std::cin >> s;    
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == 'A') {
      s[i] = '0'; 
    }
    else if (s[i] == 'C') {
      s[i] = '1'; 
    }
    else if (s[i] == 'G') {
      s[i] = '2'; 
    }
    else {
      s[i] = '3'; 
    }
  }
  for (int i = 0; i < (int) s.size(); i++) {
    position[s[i] - '0'].push_back(i);
  }
  std::string ans = ""; 
  for (int i = 0; i <= 3; i++) {
    std::reverse(position[i].begin(), position[i].end());
  }
  int curPos = -1; 
  while (position[0].empty() == false && position[1].empty() == false && position[2].empty() == false && position[3].empty() == false) {
    bool check = true; 
    for (int c = 0; c <= 3; c++) {
      while (position[c].empty() == false && position[c].back() <= curPos) {
        position[c].pop_back(); 
      }
      if (position[c].empty() == true) {
        check = false;
        break; 
      }
    }
    if (check == false) {
      break; 
    }       
    char nextChar = 'A'; 
    int maxPos = position[0].back();
    if (maxPos < position[1].back()) {
      nextChar = 'C';
      maxPos = position[1].back();
    }
    if (maxPos < position[2].back()) {
      nextChar = 'G';
      maxPos = position[2].back();
    }
    if (maxPos < position[3].back()) {
      nextChar = 'T';
      maxPos = position[3].back();
    }
    ans += nextChar; 
    curPos = maxPos; 
  }
  for (int c = 0; c <= 3; c++) {
    if (position[c].empty() == true) {
      ans += ch[c];
      break; 
    }
  }
  std::cout << ans; 
  return 0;
}