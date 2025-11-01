#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
typedef pair<int, int> pii;
int n, m;
int u, v, w;
bool visited[25];
map<int, int> adj[25];
int ans = 1e9;
int cost = 0;
int cmin = 1e9;

void dfs(int u, int time)
{
	if (time == n && adj[u].find(1) != adj[u].end())
	{
		ans = min(ans, cost + adj[u][1]);
		return;
	}
	for (auto [v, w] : adj[u])
	{
		if (visited[v])
			continue;
		visited[v] = true;
		cost += w;
		if (cost + (n - time) * cmin < ans)
			dfs(v, time + 1);
		visited[v] = false;
		cost -= w;
	}
}

void initial()
{
	cin >> n >> m;
	FOR(i, 1, m)
	{
		cin >> u >> v >> w;
		adj[u].emplace(v, w);
		cmin = min(cmin, w);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	initial();
	visited[1] = true;
	dfs(1, 1);
	cout << ans;
	return 0;
}

// chỉ giải đc 90%