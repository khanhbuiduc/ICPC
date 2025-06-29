#include <iostream>
#include <string>
#include <vector>
#include <map> 
const std::string mychar[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
std::map <std::string, int> mymap; 
int value = 0; 

void init1() {
  for (int a = 0; a <= 25; a++) {
    mymap[mychar[a]] = ++value;   
  }
}

void init2() {
  for (int a = 0; a <= 25; a++) {
    for (int b = a + 1; b <= 25; b++) {
      mymap[mychar[a] + mychar[b]] = ++value;
    }
  }
}

void init3() {
  for (int a = 0; a <= 25; a++) {
    for (int b = a + 1; b <= 25; b++) {
      for (int c = b + 1; c <= 25; c++) {
        mymap[mychar[a] + mychar[b] + mychar[c]] = ++value;
      }
    }
  }
}

void init4() {
  for (int a = 0; a <= 25; a++) {
    for (int b = a + 1; b <= 25; b++) {
      for (int c = b + 1; c <= 25; c++) {
        for (int d = c + 1; d <= 25; d++) {
          mymap[mychar[a] + mychar[b] + mychar[c] + mychar[d]] = ++value;
        } 
      }
    }
  }
}

void init5() {
  for (int a = 0; a <= 25; a++) {
    for (int b = a + 1; b <= 25; b++) {
      for (int c = b + 1; c <= 25; c++) {
        for (int d = c + 1; d <= 25; d++) {
          for (int e = d + 1; e <= 25; e++) {
            mymap[mychar[a] + mychar[b] + mychar[c] + mychar[d] + mychar[e]] = ++value;                 
          }
        } 
      }
    }
  }
}

int main () {
  init1();
  init2();
  init3();
  init4();
  init5();
  std::string word; 
  while (std::cin >> word) {
    std::cout << mymap[word] << std::endl;
  }
  return 0; 
}