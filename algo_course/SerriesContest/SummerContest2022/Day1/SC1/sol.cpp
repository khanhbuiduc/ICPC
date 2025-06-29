#include <bits/stdc++.h> 

using namespace std;
int numTest; 
string name[4]; 
int cnt[4]; 

int main () {
  freopen("SC1.INP", "r", stdin);
  freopen("SC1.OUT", "w", stdout); 
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> name[0] >> name[1] >> name[2] >> name[3]; 
    memset(cnt, 0, sizeof(cnt)); 
    for (int i = 0; i < 52; i++) {
      pair <string, string> card;
      cin >> card.first >> card.second;  
      if (card.first == "2") {
        cnt[i % 4]++; 
      }
    }
    bool found = false; 
    for (int i = 0; i < 4; i++) {
      if (cnt[i] == 4) {
        cout << name[i] << " is absolute winner" << endl; 
        found = true; 
        break; 
      }
    } 
    if (found ==  false) {
      cout << "The game has started" << endl; 
    } 
  }
  return 0; 
}