#include <iostream>
#include <string> 
#include <deque>
int cnt[26]; 
 
int main () {
  std::string s;
  std::cin >> s; 
  for (int i = 0; i < (int) s.size(); i++) {
    cnt[s[i] - 'A']++; 
  }
  int cntOdd = 0;
  for (int c = 0; c < 26; c++) {
    if (cnt[c] % 2 == 1) {
      cntOdd++; 
    }
  }
  if (cntOdd > 1) {
    std::cout << "NO SOLUTION"; 
  }
  else {
    std::deque <char> mydeque; 
    int cOdd = -1; 
    for (int c = 0; c < 26; c++) {
      if (cnt[c] % 2 == 1) {
        cOdd = c; 
      }
    }
    if (cOdd != -1) {
      for (int i = 1; i <= cnt[cOdd]; i++) {
        mydeque.push_back((char) (cOdd + 'A')); 
      }
    }
    for (int c = 0; c < 26; c++) {
      if (c != cOdd) {
        for (int i = 1; i <= cnt[c] / 2; i++) {
          mydeque.push_back((char) (c + 'A')); 
        }
      }
    }
    for (int c = 0; c < 26; c++) {
      if (c != cOdd) {
        for (int i = 1; i <= cnt[c] / 2; i++) {
          mydeque.push_front((char) (c + 'A')); 
        }
      }
    }
    for (int i = 0; i < (int) mydeque.size(); i++) {
      std::cout << mydeque[i];
    }
  }
  return 0;
}