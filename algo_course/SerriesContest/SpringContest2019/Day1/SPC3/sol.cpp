#include <bits/stdc++.h> 

using namespace std; 

const long long MOD = 1000000007LL; 
const int MAX_N = 105; 

long long dp[MAX_N]; 
vector <int> adj[MAX_N]; 
bool mark[MAX_N]; 
int n, test; 

long long DFS(int u, int father) {
	if (dp[u] != 0) {
		return dp[u]; 
	}	

	long long res = 1LL; 

	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i]; 

		if (v == father || mark[v] == true) {
			continue; 
		}

		(res *= (DFS(v, u) + 1) % MOD) %= MOD; 
	}

	dp[u] = res; 
	return dp[u]; 
}

int getSum(const vector <int> &p, const vector <int> &x) {
	for (int i = 1; i < n; i++) {
		adj[i + 1].push_back(p[i - 1]); 
		adj[p[i - 1]].push_back(i + 1); 
	}			

	long long res = 0LL; 

	for (int b = 0; b <= 31; b++) {
		memset(mark, false, sizeof(mark)); 
		for (int i = 1; i <= n; i++) {	
			if (((long long) x[i - 1] & (1LL << (long long) b)) > 0) {
				mark[i] = true; 
				memset(dp, 0, sizeof(dp)); 
				long long cnt = DFS(i, -1); 
				(res += (cnt * (1LL << (long long) b)) % MOD) %= MOD; 
			} 
		}
	}

	return (int) res; 
}

int main () {
	freopen("SPC3.INP", "r", stdin);
	freopen("SPC3.OUT", "w", stdout);
	cin >> test; 
	for (int tt = 1; tt <= test; tt++) {
		cin >> n; 
		for (int i = 1; i <= n; i++) {
			adj[i].clear(); 
		}

		vector <int> p, x; 
		for (int i = 1; i < n; i++) {
			int v; 
			cin >> v; 
			p.push_back(v); 
		}
		                 
		for (int i = 1; i <= n; i++) {
			int v; 
			cin >> v; 
			x.push_back(v); 
		}            

		int res = getSum(p, x); 
		cout << res << endl; 
	}
	return 0; 
}