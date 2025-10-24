#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int INF = 1e9;

int n;
int c[MAXN][MAXN];
int x[MAXN];
bool visited[MAXN];
int ans = INF;
int cost = 0;
int cmin = INF;
void backtrack(int i)
{
	for (int city = 1; city <= n; city++)
	{
		if (!visited[city])
		{
			visited[city] = true;
			x[i] = city;
			cost += c[x[i - 1]][x[i]];

			if (i == n)
			{
				ans = min(ans, cost + c[x[n]][1]);
			}
			else if (cost + (n - i + 1) * cmin < ans)
			{
				backtrack(i + 1);
			}

			visited[city] = false;
			cost -= c[x[i - 1]][x[i]];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			if (c[i][j] > 0)
			{
				cmin = min(cmin, c[i][j]);
			}
		}
	}
	x[1] = 1;
	visited[1] = true;
	backtrack(2);
	if (ans == INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}

	return 0;
}

// cạnh min: (u-v) = cmin
// back_track( i ) // lần thứ i thăm thành phố.
// 	duyệt city: 1->n
// 		nếu city chưa thăm
// 			visited[ city ] = true
// 			x[i] = city;
// 			cost += c[ x[i-1] ][ X[i] ]
// 			nêu  i == n
// 				ans = min(ans, cost + c[X[n]] [1] )
// 			else nếu ans > (d + (n-1+1)*cmin)
// 				recusion( i+1 )
// 			// back track
// 			visited[j]  = 0
// 			cost -= c[X[n]] [1];
