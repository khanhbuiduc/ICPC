#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 55; 
int test; 
int B;
long long M; 
int a[MAX_N][MAX_N]; 

int main () {
	freopen("SPC6.INP", "r", stdin);
	freopen("SPC6.OUT", "w", stdout); 
	cin >> test; 
	for (int tt = 1; tt <= test; tt++) {
		cin >> B >> M;
		if (M > (1LL << (long long) (B - 2))) {
			cout << "IMPOSSIBLE" << endl; 
			continue; 
		}

		cout << "POSSIBLE" << endl; 
		for (int i = 1; i <= B; i++) {
			for (int j = 1; j <= B; j++) {
				a[i][j] = 0; 
			}
		}

		a[1][B] = 1; 
		M--; 
		for (int i = 2; i <= B; i++) {
			for (int j = i + 1; j <= B; j++) {
				a[i][j] = 1; 
			}
		}

		for (int i = 2; i < B; i++) {
			int t = B - i - 1; 
			if ((M & (1LL << (long long) t)) > 0) {
				a[1][i] = 1; 
			}
		}

		for (int i = 1; i <= B; i++) {
			for (int j = 1; j <= B; j++) {
				cout << a[i][j]; 
			}

			cout << endl; 
		}
	}
	return 0; 
}