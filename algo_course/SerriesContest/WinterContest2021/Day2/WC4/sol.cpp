#include <iostream> 
#include <cstring>
#include <fstream>
#include <string> 

using namespace std; 
const int MAX_LENGTH = 105; 
const int MOD = 1000000007;
int numTest;
int pos[MAX_LENGTH][26]; 
int dp[MAX_LENGTH][105][2][2]; 
string s1, s2, banned; 

void createLastPos(const string &s) {
  memset(pos, 0, sizeof(pos)); 
  int n = (int) s.size();
  string st = "";
  for (int i = 1; i < n; i++) {
    st += s[i - 1]; 
    for (int c = 0; c <= 25; c++) {
      string tmp = st;
      tmp += (char) (c + 'a');
      for (int j = i + 1; j >= 1; j--) {
        if (c == s[j - 1] - 'a') {
          int p = i + 1;
          int q = j; 
          while (q > 0) {
            if (s[q - 1] != tmp[p - 1]) {
              break;
            }
            p--;
            q--;
          }
          if (q == 0) {
            pos[i][c] = j;
            break;
          }
        }
      }
    }
  }
}

void dynamicProgramming() {
  memset(dp, 0, sizeof(dp)); 
  int n = (int) s1.size();
  int lenBanned = (int) banned.size();
  dp[0][0][1][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < lenBanned; j++) {
      for (int state1 = 0; state1 <= 1; state1++) {
        for (int state2 = 0; state2 <= 1; state2++) {
          if (dp[i][j][state1][state2] == 0) {
            continue;
          }
          for (int nextChar = 0; nextChar <= 25; nextChar++) {
            if (j == lenBanned - 1 && nextChar == banned[j] - 'a') {
              continue;
            }
            if (state1 == 1 && nextChar < s1[i] - 'a') {
              continue;
            }
            if (state2 == 1 && nextChar > s2[i] - 'a') {
              continue; 
            }
            int nextState1 = state1; 
            if (state1 == 1 && nextChar > s1[i] - 'a') {
              nextState1 = 0;
            }
            int nextState2 = state2;
            if (state2 == 1 && nextChar < s2[i] - 'a') {
              nextState2 = 0;
            }
            int nextj = 0; 
            if (j == 0) {
              if (nextChar == banned[j] - 'a') {
                nextj = 1; 
              }
            }
            else {
              nextj = pos[j][nextChar];
            }
            if (nextj == lenBanned) {
              continue; 
            }
            (dp[i + 1][nextj][nextState1][nextState2] += dp[i][j][state1][state2]) %= MOD; 
          }
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < lenBanned; j++) {
    for (int state1 = 0; state1 <= 1; state1++) {
      for (int state2 = 0; state2 <= 1; state2++) {
        (ans += dp[n][j][state1][state2]) %= MOD; 
      }
    }   
  }
  cout << ans << endl;   
}

int main () {
  freopen("WC4.INP", "r", stdin);
  freopen("WC4.OUT", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s1 >> s2 >> banned;
    createLastPos(banned);
    dynamicProgramming();     
  }
  return 0; 
}