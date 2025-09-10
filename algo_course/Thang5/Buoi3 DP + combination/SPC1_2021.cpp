#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAXN = 1005;
ll f[MAXN][MAXN];
int n, k;
int a[MAXN];
int sum_children = 0;

void initial()
{
    cin >> n >> k;
    sum_children = 0;
    FOR(i, 0, n)
    FOR(j, 0, k)
    f[i][j] = 0;
    FOR(i, 1, n)
    {
        cin >> a[i];
        sum_children += a[i];
    }
    f[0][0] = 1;
}
ll power_mod(ll a, ll b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        initial();
        FOR(i, 0, n - 1)
        FOR(j, 0, k)
        {
            if (f[i][j] == 0)
                continue;
            if (j + 1 <= k)
                f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j] * (k - j)) % MOD;
            f[i + 1][j] = (f[i + 1][j] + f[i][j] * j) % MOD;
        }
        ll ans = 0;
        FOR(j, 1, k)
        {
            if (f[n][j] == 0)
                continue;
            ans = (ans + (f[n][j] * power_mod((k - j + 1), sum_children))) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
/* n người mẹ ngồi j bàn. mỗi người con có thể ngồi (K - j + 1) bàn

tổng con: suma[n]
tổng số cách mà tất cả người con ngồi (K - j + 1) ^ suma[n]


f[i][j] là số tổ hợp mà xét i người mẹ. j bàn được sử dụng

bài toán cơ sở:
    f[0][0] = 1;
QHD:
    f[i][j] > 0
    xét bà mẹ i + 1:
        +> ngồi bàn mới: f[i+1][j+1] += f[i][j] * (K - j);
        +> nguồi cùng bàn với mẹ cũ: f[i+1][j] += f[i][j] * (j)
*/