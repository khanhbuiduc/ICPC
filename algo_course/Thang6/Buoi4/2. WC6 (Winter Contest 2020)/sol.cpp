#include <iostream>
#include <string>
#include <fstream> 
#include <algorithm>
int numTest; 
std::string s;
long long pos; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s >> pos;
    pos--;     
    std::string rev_s = s; 
    std::reverse(rev_s.begin(), rev_s.end()); 
    std::string st = s; 
    st += rev_s; 
    int len = (int) st.size();
    pos %= len; 
    std::cout << st[pos] << std::endl;
  }   
  return 0; 
}