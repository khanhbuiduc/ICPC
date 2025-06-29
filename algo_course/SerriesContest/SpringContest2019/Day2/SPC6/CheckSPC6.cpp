#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 55; 
struct element {
	string verd; 
	string s[MAX_N];  
};

vector <pair <long long, long long> > a; 
vector <element> b; 
int test; 
vector <int> adj[MAX_N]; 
long long f[MAX_N][MAX_N];
int mark[MAX_N];
bool check;

void DFS(int u) {
	mark[u] = 1; 
	for (int i = 0; i < (int) adj[u].size(); i++) {
		int v = adj[u][i]; 
		if (mark[v] == 0) {
			DFS(v); 
		}
		else if (mark[v] == 1) {
			check = true; 
			return; 
		}
	}
	mark[u] = 2;
} 

void DynamicProgramming(int N) {
	f[0][0] = 1; 
	for (int step = 0; step < N; step++) {
		for (int u = 0; u < N; u++) {
			if (f[u][step] == 0) {
				continue; 
			}

			for (int i = 0; i < (int) adj[u].size(); i++) {
				int v = adj[u][i]; 
				f[v][step + 1] += f[u][step]; 
			}
		}
	}
}

bool compare(const pair <long long, long long> &A, const element &B) {
	long long M = A.second; 
	long long N = A.first;
	vector <string> ss; 
	if (B.verd != "POSSIBLE" && B.verd != "IMPOSSIBLE") {
		return false; 
	}

	if (B.verd == "IMPOSSIBLE") {
		if (M <= (1LL << (N - 2))) {
			return false; 
		}
		else {
			return true; 
		}		
	}
	else {
		for (int i = 0; i < N; i++) {
			adj[i].clear(); 
			for (int j = 0; j < N; j++) {
				f[i][j] = 0;
			}
			 
			mark[i] = 0; 
		}

		for (int i = 0; i < N; i++) {
			if (B.s[i].empty() == true) {
				return false; 
			}

			ss.push_back(B.s[i]); 
		}

		for (int i = 0; i < N; i++) {
			if ((int) ss[i].size() != N) {
				return false; 
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ss[i][j] == '1') {
					adj[i].push_back(j); 
				}
			}	
		}

		DFS(0); 
		if (check == true) {
			return false; 
		}

		DynamicProgramming(N); 
		long long sum = 0LL;
		for (int i = 0; i < N; i++) {
			sum += f[N - 1][i]; 
		} 

		return (sum == M); 
	}
}

int main () {
	freopen("SPC6.INP", "r", stdin);
	cin.clear(); 
	cin >> test; 
	for (int i = 1; i <= test; i++) {
		long long B, M; 
		cin >> B >> M; 
		a.push_back(make_pair(B, M)); 
	}

	freopen("SPC6.OUT", "r", stdin);
	cin.clear();
	for (int t = 1; t <= test; t++) {
		element E; 
		cin >> E.verd; 
		if (E.verd == "POSSIBLE") {
			for (int i = 0; i < (int) a[t - 1].first; i++) {
				cin >> E.s[i]; 
			} 
		}

		b.push_back(E); 
	} 

	//freopen("output.txt", "w", stdout);

	bool ok = true; 
	for (int t = 0; t < test; t++) {
		ok &= compare(a[t], b[t]); 
	}
                                       
	if (ok == true) {
		cout << "Correct" << endl; 
		cout << 1.0 << endl; 
	}
	else {
		cout << "Wrong Answer" << endl; 
		cout << 0.0 << endl; 
	}

	return 0; 
}