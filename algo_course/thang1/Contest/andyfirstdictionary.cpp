#include <iostream> 
#include <set>
#include <string> 

int main () {
  std::set <std::string> myset; 
  std::string word;
  while (std::cin >> word) {
    std::string renewWord = ""; 
    for (int i = 0; i < (int) word.size(); i++) {
      if ('A' <= word[i] && word[i] <= 'Z') {
        word[i] = word[i] - 'A' + 'a'; 
      }
    }
    for (int i = 0; i < (int) word.size(); i++) {
      if ('a' <= word[i] && word[i] <= 'z') {
        renewWord += word[i];
      }
      else {
        if (renewWord != "") {
          myset.insert(renewWord);
        }
        renewWord = ""; 
      }
    }
    if (renewWord.empty() == true) {
      continue;
    }
    myset.insert(renewWord);
  }
  for (std::set <std::string>::iterator it = myset.begin(); it != myset.end(); it++) {
    std::cout << *it << std::endl;
  }
  return 0; 
}