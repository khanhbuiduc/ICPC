#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct element {
  string name;
  int oxh;
  int numElement;
};

vector <element> listElement;
string s;
int numTest;

int main () {
  freopen("SPC4.INP", "r", stdin);
  freopen("SPC4.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    listElement.clear();
    int l = -1;
    int r = -1;
    for (int i = 0; i < (int) s.size(); i++) {
      if ('A' <= s[i] && s[i] <= 'Z') {
        string name = "";
        name += s[i];
        listElement.push_back((element) {name, 1000, 1});
      }
      else if ('a' <= s[i] && s[i] <= 'z') {
        listElement.back().name += s[i];
      }
      else if ('0' <= s[i] && s[i] <= '9') {
        int numb = s[i] - '0';
        if (l == -1 || r == -1) {
          listElement.back().numElement = numb;
        }
        else {
          for (int j = l; j <= r; j++) {
            listElement[j].numElement *= numb;
          }
          l = -1;
          r = -1;
        }
      }
      else if (s[i] == '(') {
        l = (int) listElement.size();
      }
      else {
        r = (int) listElement.size() - 1;
      }
    }
    int ans = 0;
    for (int i = 1; i < (int) listElement.size(); i++) {
      string name;
      int num;
      cin >> name >> num;
      name.pop_back();
      for (int j = 0; j < (int) listElement.size(); j++) {
        if (listElement[j].name == name) {
          listElement[j].oxh = num;
        }
      }
    }
    int p = -1;
    for (int i = 0; i < (int) listElement.size(); i++) {
      if (listElement[i].oxh == 1000) {
        p = i;
        continue;
      }
      ans -= listElement[i].oxh * listElement[i].numElement;
    }
    ans /= listElement[p].numElement;
    cout << ans << endl;
  }
  return 0;
}