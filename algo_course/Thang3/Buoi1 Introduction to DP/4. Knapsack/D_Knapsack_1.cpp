#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
pii a[105];
ll f[105][100'005]; //
int n, w;
void knapsack()
{
    memset(f, 0, sizeof(f));
    // btcs f[i][0]= 0,f[0][i] = 0
    FOR(i, 1, n)
    FOR(j, 0, w)
    {
        auto [wi, vi] = a[i];
        // bỏ qua i
        f[i][j] = f[i - 1][j];
        // cho đồ thứ i vào balo
        if (j >= wi)
            f[i][j] = max(f[i][j], f[i - 1][j - wi] + vi);
    }
}
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i].ff >> a[i].ss;
    // đáp án:
    knapsack();
    cout << f[n][w] << endl;
}