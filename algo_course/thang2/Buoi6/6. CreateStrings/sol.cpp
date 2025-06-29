#include <iostream> 
#include <string>
#include <vector>
std::string s; 
std::vector <std::string> ans; 
std::string st;
int cnt[26];
int len;  

void backTracking(int pos) {
  for (int c = 0; c < 26; c++) {
    if (cnt[c] > 0) {
      st[pos] = (char) (c + 'a'); 
      cnt[c]--; 
      if (pos < len - 1) {
        backTracking(pos + 1); 
      }
      else {
        ans.push_back(st); 
      }
      cnt[c]++; 
    }
  }
}

int main () {
  std::cin >> s;
  len = (int) s.size();
  st.resize(len); 
  for (int i = 0; i < len; i++) {
    cnt[s[i] - 'a']++; 
  }
  backTracking(0);  
  std::cout << (int) ans.size() << std::endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i] << std::endl;
  }
  return 0;
}