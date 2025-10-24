#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;

template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}

typedef long long ll;
int n, k, cnt_badk;
const ll inf = -100'000'000'000'007LL;
int a[100'005];
ll f[100'005][32], pow2[32];

void cac_pow2()
{
    pow2[0] = 1;
    FOR(i, 1, 30) { pow2[i] = 2ll * pow2[i - 1]; }
}

void initial()
{
    cin >> n >> k;
    FOR(i, 1, n)
    cin >> a[i];
    FOR(i, 0, n)
    {
        FOR(j, 0, 30) { f[i][j] = inf; }
    }
    f[0][0] = 0;
}

void solve()
{
    FOR(i, 0, n - 1)
    {
        FOR(j, 0, 30)
        {
            if (f[i][j] == inf)
                continue;
            maximize(f[i + 1][j], f[i][j] + a[i + 1] / pow2[j] - k);
            if (j < 30)
                maximize(f[i + 1][j + 1], f[i][j] + a[i + 1] / pow2[j + 1]);
        }
    }

    ll ans = inf;
    FOR(i, 0, n)
    FOR(j, 0, 30)
    {
        ans = max(ans, f[i][j]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cac_pow2();
    while (t--)
    {
        initial();
        solve();
    }
    return 0;
}
// gọi f[i][j] là tổng lượng đồng xu lớn nhất khi có i rương đầu tiên, sử dụng j badkey
/*
ai<10^9 => ai chia tối đa 2^30 lần thì thành 0;
bài toán cơ sở: f[i][j]= -1, f[0][0] = 0;
đáp án: Max(f[n][j]) j: 1->30;
xét rương i+1
    dùng badkey:
        f[i+1][max(30,j+1)] = max(f[i+1][max(30,j+1)], f[i][j] + a[i+1]/pow2[max(30,j+1)])
    dùng goodkey
        f[i+1][j] = max(f[i+1][j], f[i][j] + a[i+1]/pow2[j] - c)
*/