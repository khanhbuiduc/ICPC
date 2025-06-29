#include <bits/stdc++.h> 
 
using namespace std;
 
const int MAX_N = 20;
 
int test;
long long dp[MAX_N][MAX_N][10][3]; 
 
string change(long long x) {
	string res = ""; 
	long long val = x; 
 
	while (val) {
		res += (char) (val % 10 + '0'); 
		val /= 10; 
	}
	reverse(res.begin() , res.end()); 
	return res; 
}
 
long long calc(long long val) {
	if (val <= 0) {
		return 0LL; 
	}
	string s = change(val);
 
 	int len = (int) s.size();
 	long long res = 0;  
 	int x = s[0] - '0'; 
 	for (int l = 1; l < MAX_N; l++) {
 		for (int num = 0; num < MAX_N; num++) {
 			for (int d = 0; d < 10; d++) {
 				for (int b = 0; b <= 2; b++) {
 					dp[l][num][d][b] = 0;
 				}
 			}
 		}
 	}
 
 	for (int d = 1; d <= 9; d++) {
 		if (d == x) {
 			dp[1][1][d][1]++;
 			for (int t = 1; t <= 9; t++) {
 				if (t != d) {
 					dp[1][0][t][1]++;
 				}
 			} 
 		}
 		else {
 			if (d < x) {
 				dp[1][1][d][0]++;
 				for (int t = 1; t <= 9; t++) {
 					if (t != d) {
 						dp[1][0][t][0]++; 
 					}
 				}
 			}
 			else {
 				dp[1][1][d][2]++;
 				for (int t = 1; t <= 9; t++) {
 					if (t != d) {
 						dp[1][0][t][2]++; 
 					}
 				}			
 			}
 		}
 	}
      
 	for (int l = 1; l < len; l++) {
 		for (int num = 0; num <= l; num++) {
 			for (int d = 0; d <= 9; d++) {
 				for (int b = 0; b <= 2; b++) {
 					//cout << l << ' ' << num << ' ' << d << ' ' << b << ' ' << dp[l][num][d][b] << endl; 
 					x = s[l] - '0'; 
 				
 				  if (b == 0) {
 				  	for (int t = 0; t <= 9; t++) {
 				  		dp[l + 1][num + (t == d)][d][0] += dp[l][num][d][b]; 
 				  	}	
 				  }
 				  else {
 				  	if (b == 1) {
 				  		for (int t = 0; t < x; t++) {
 				  			dp[l + 1][num + (t == d)][d][0] += dp[l][num][d][b]; 
 				  		}
 				  		dp[l + 1][num + (x == d)][d][1] += dp[l][num][d][b]; 
 				  		for (int t = x + 1; t <= 9; t++) {
 				  			dp[l + 1][num + (t == d)][d][2] += dp[l][num][d][b]; 
 				  		}
 				  	}
 				  	else {
 				  		for (int t = 0; t <= 9; t++) {
 				  			dp[l + 1][num + (t == d)][d][2] += dp[l][num][d][b]; 
 				  		}
 				  	}
 				  }
 				}
 			}
 		}
 	}
 
 	for (int l = 1; l < len; l++) {
 		for (int num = 1; num <= l; num++) {
 			for (int d = 1; d <= 9; d++) {
 				res += 1LL * d * num * (dp[l][num][d][0] + dp[l][num][d][1] + dp[l][num][d][2]); 
 			}
 		}
 	}
 
 	for (int num = 1; num <= len; num++) {
 		for (int d = 1; d <= 9; d++) {
 			res += 1LL * d * num * (dp[len][num][d][0] + dp[len][num][d][1]); 
 		}
 	}
 
 	return res; 
}
 
int main () {
	freopen("SPC1.INP", "r", stdin);
	freopen("SPC1.OUT", "w", stdout);
	scanf("%d" , &test); 
 
	while (test--) {
		long long a , b; 
		scanf("%lld %lld" , &a , &b); 
		printf("%lld\n" , calc(b) - calc(a - 1)); 
	}
	return 0; 
} 