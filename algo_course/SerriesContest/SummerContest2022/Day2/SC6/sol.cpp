#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 10005; 
const int MAX_K = 205; 
const long long inf = -1000000000000007LL; 
int a[MAX_N]; 
long long dp[MAX_N][MAX_K][3][3]; 
int n, k, numTest;

long long calc(int curstate, int nextstate, int numbSegment) {
  if (numbSegment == 1) {
    if (nextstate == 1) {
      return -1; 
    }
    else if (nextstate == 2) {
      return 1; 
    }
  }
  if (numbSegment == k) {
    if (nextstate == 1) {
      return 1; 
    }
    else if (nextstate == 2) {
      return -1; 
    }
  }
  if (curstate == nextstate) {
    return 0LL; 
  }
  else if (curstate == 1 && nextstate == 2) {
    return 2LL; 
  }
  else if (curstate == 2 && nextstate == 1) {
    return -2LL; 
  }
}

void update(long long &a, long long b) {
  a = max(a, b); 
}

int main () {
  freopen("SC6.INP", "r", stdin);
  freopen("SC6.OUT", "w", stdout); 
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        for (int prevstate = 0; prevstate <= 2; prevstate++) {
          for (int curstate = 0; curstate <= 2; curstate++) {
            dp[i][j][prevstate][curstate] = inf; 
          }
        }
      }
    }
    dp[1][1][0][1] = -a[1];
    dp[1][1][0][2] = a[1];
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= k; j++) {
        for (int prevstate = 0; prevstate <= 2; prevstate++) {
          for (int curstate = 1; curstate <= 2; curstate++) {
            if (dp[i][j][prevstate][curstate] == inf) {
              continue; 
            }
            long long curValue = dp[i][j][prevstate][curstate]; 
            long long mul = calc(prevstate, curstate, j); 
            update(dp[i + 1][j][prevstate][curstate], curValue + mul * a[i + 1]); 
            if (j == k - 1) {
              mul = calc(prevstate, curstate, j + 1); 
              update(dp[i + 1][j + 1][prevstate][curstate], curValue + mul * a[i + 1]); 
            }
            else if (j < k - 1) {
              mul = calc(curstate, 1, j + 1);
              update(dp[i + 1][j + 1][curstate][1], curValue + mul * a[i + 1]);
              mul = calc(curstate, 2, j + 1);
              update(dp[i + 1][j + 1][curstate][2], curValue + mul * a[i + 1]); 
            }
          }
        }
      }
    }
    long long ans = inf;  
    for (int prevstate = 0; prevstate <= 2; prevstate++) {
      for (int curstate = 1; curstate <= 2; curstate++) {
        update(ans, dp[n][k][prevstate][curstate]); 
      }
    }
    cout << ans << endl;
  }  
  return 0; 
}