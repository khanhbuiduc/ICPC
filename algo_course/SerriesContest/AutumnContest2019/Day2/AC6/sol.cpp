#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 55;       

int dp[MAX_N][MAX_N]; 
vector <int> save[MAX_N];
int color[MAX_N], sweet[MAX_N];
int n, K, test;  
bool comp(int a, int b) {
  return a > b; 
}
     
int main () {
  freopen("AC6.INP", "r", stdin);
  freopen("AC6.OUT", "w", stdout);
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> n >> K; 
    for (int i = 0; i < n; i++) {
      cin >> color[i] >> sweet[i]; 
    }
    for (int i = 0; i < MAX_N; i++) {
      save[i].clear(); 
    }                         
    for (int i = 0; i < n; i++) {
      save[color[i]].push_back(sweet[i]); 
    }                
    for (int i = 1; i <= 50; i++) {
      sort(save[i].begin(), save[i].end(), comp); 
    }
    for (int i = 0; i < MAX_N; i++) {
      for (int j = 0; j < MAX_N; j++) {
        dp[i][j] = -1; 
      }
    }
    dp[0][0] = 0; 
    for (int i = 0; i < 50; i++) {
      for (int j = 0; j <= 2 * K; j++) {
        if (dp[i][j] == -1) {
          continue; 
        }
        int sum = 0;
        for (int jj = 0; jj <= (int) save[i + 1].size() && jj <= 2 * K - j && jj <= K; jj++) {
          if (jj > 0) {
            sum += save[i + 1][jj - 1]; 
          }
          if (dp[i + 1][j + jj] < dp[i][j] + sum) {
            dp[i + 1][j + jj] = dp[i][j] + sum;
          }  
        }
      }
    }
    cout << dp[50][2 * K] << endl;    
  }
  return 0; 
}