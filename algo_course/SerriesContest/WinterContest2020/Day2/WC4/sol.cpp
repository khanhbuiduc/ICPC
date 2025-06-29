#include <iostream> 

using namespace std;
const int MAX_N = 102; 
const int MOD = 1000000007; 
int dp[MAX_N][MAX_N];
int C[MAX_N][MAX_N]; 
int n, k, numTest; 

void init() {
  for (int i = 0; i < MAX_N; i++) {
    C[i][0] = 1; 
    C[i][i] = 1; 
  }
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD; 
    }
  }
}

void DynamicProgramming() {
  dp[1][1] = 1; 
  dp[2][1] = 1; 
  for (int i = 3; i < MAX_N; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j]; 
      int sum = 0; 
      for (int x = 1; x <= i - 2; x++) {
        for (int k = 1; k < j; k++) {
          long long mul = 1LL * (i - 2) % MOD; 
          (mul *= 1LL * dp[x][k]) %= MOD;
          (mul *= 1LL * dp[i - 1 - x][j - k]) %= MOD;
          (mul *= 1LL * C[i - 3][x - 1]) %= MOD;
          (sum += mul) %= MOD;  
        }  
      }
      (dp[i][j] += sum) %= MOD; 
    }
  }
}

int main () {
  freopen("WC4.INP", "r", stdin);
  freopen("WC4.OUT", "w", stdout);
  init();
  DynamicProgramming();  
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k; 
    long long res = 1LL; 
    (res *= 1LL * dp[n - 1][k]) %= MOD; 
    (res *= 1LL * n) %= MOD;
    (res *= 1LL * (n - 1)) %= MOD; 
    cout << res << endl; 
  }  
  return 0; 
}