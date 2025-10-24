#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
using namespace std;
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
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
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
/// template
const int mod = 998'244'353;
typedef long long ll;
int n, a[20];
ll f[20][20];
void initial()
{
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i];
    f[1][0] = 1;
}
void solve()
{
    FOR(i, 1, n - 1)
    FOR(h, 0, i - 1)
    {
        if (f[i][h] == 0)
            continue;
        FOR(hh, 1, h + 1)
        {
            // đỉnh i+1 có thể có độ cao hh: 1 -> h+1; mỗi độ cao, đỉnh i+1 có thể chọn kết nối với đỉnh trc đó  1->hh-1
            (f[i + 1][hh] += f[i][h] * (1 << (hh - 1))) %= mod;
        }
    }
    ll ans = 0;
    FOR(h, 0, n)
    {
        (ans += f[n][h]) %= mod;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    initial();
    solve();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}
