#include <bits/stdc++.h>
using namespace std;
const long long INF = 1'000'000'000;
typedef long long ll;
ll f[105][100'005]; // tổng khổi lượng max: tổng giá trị là v và,  tổng
int v[105], w[105];
void minWeight(ll &a, ll b)
{
    a = min(a, b);
}
int main()
{
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    ll maxPrice = 0;
    for (int i = 1; i <= n; i++)
        maxPrice += v[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= maxPrice; j++)
            f[i][j] = INF;
    f[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= maxPrice; j++)
        {
            if (f[i][j] == INF)
                continue;
            minWeight(f[i + 1][j], f[i][j]);
            minWeight(f[i + 1][j + v[i + 1]], f[i][j] + w[i + 1]);
        }
    ll res = 0;
    for (int j = 0; j <= maxPrice; j++)
        if (0 < f[n][j] && f[n][j] <= W)
        {
            res = j;
        }
    cout << res;
}