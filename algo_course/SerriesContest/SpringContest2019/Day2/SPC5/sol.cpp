#include <bits/stdc++.h> 

using namespace std; 
const long long MOD = 1000000007; 
const int MAX_N = 1005; 

long long dp[MAX_N][MAX_N][2][2]; 
int n, k, test; 
long long F[MAX_N], invF[MAX_N];
long long C[MAX_N][MAX_N];
long long cnt[MAX_N];

void add(long long &a, long long b) {
    (a += b) %= MOD; 
}

void init() {
    F[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        F[i] = (1LL * F[i - 1] * i) % MOD; 
    }

    for (int i = 0; i < MAX_N; i++) {
        C[i][0] = C[i][i] = 1LL; 
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD; 
        }
    }
}

int main () {
    init(); 
    cin >> test; 
    for (int tt = 1; tt <= test; tt++) {
        cin >> n >> k;
        for (int i = 0; i < MAX_N; i++) {
            cnt[i] = 0; 
            for (int j = 0; j < MAX_N; j++) {
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        dp[i][j][x][y] = 0; 
                    }
                }
            }
        } 

        dp[0][0][1][0] = 1; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int x = 0; x <= 1; x++) {
                    for (int y = 0; y <= 1; y++) {
                        if (dp[i][j][x][y] > 0) {
                            long long cur = dp[i][j][x][y]; 
                            add(dp[i + 1][j][y][0], cur); 
                            if (x == 0) {
                                add(dp[i + 1][j + 1][y][0], cur); 
                            }

                            if (i < n) {
                                add(dp[i + 1][j + 1][y][1], cur);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            cnt[i] = (dp[n][i][0][0] + dp[n][i][1][0]) % MOD; 
            (cnt[i] *= F[n - i]) %= MOD; 
        }    
  
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= n; j++) {
                cnt[i] = (cnt[i] - (C[j][i] * cnt[j]) % MOD + MOD) % MOD;
            }
        }     
    
        cout << cnt[k] << endl;  
    }
    return 0; 
}
