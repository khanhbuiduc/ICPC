int f[1005][105][2]; 
class Solution {
public:
    void update(int &a, int b) {
        a = max(a, b); 
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = (int) prices.size();
        const int inf = -200005;  
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                f[i][j][0] = inf; 
                f[i][j][1] = inf; 
            }
        }
        f[1][0][0] = 0; 
        f[1][1][1] = 0; 
        for (int i = 1; i < n; i++) {
            for (int numbTransactions = 0; numbTransactions <= k; numbTransactions++) {
                for (int state = 0; state <= 1; state++) {
                    if (f[i][numbTransactions][state] == inf) {
                        continue; 
                    }
                    int currentValue = f[i][numbTransactions][state];
                    update(f[i + 1][numbTransactions][0], currentValue);
                    if (state == 1) {
                        update(f[i + 1][numbTransactions][1], currentValue + prices[i] - prices[i - 1]);
                    }
                    if (numbTransactions < k) {
                        update(f[i + 1][numbTransactions + 1][1], currentValue);
                    }     
                }
            }
        }
        int ans = inf; 
        for (int numbTransactions = 0; numbTransactions <= k; numbTransactions++) {
            update(ans, f[n][numbTransactions][0]);
            update(ans, f[n][numbTransactions][1]);
        }
        return ans;
    }
};