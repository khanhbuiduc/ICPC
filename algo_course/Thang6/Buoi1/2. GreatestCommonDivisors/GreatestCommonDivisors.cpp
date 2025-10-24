#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define MOD 1'000'000'007
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
typedef long long ll;
#define MOD 1'000'000'007
ll f[105][75];
int a[105];

int n;
void initial()
{
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i];
    // reset f
    FOR(i, 0, n)
    FOR(j, 0, 70) { f[i][j] = 0; }
    //
    f[0][0] = 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        initial();
        FOR(i, 0, n - 1)
        FOR(g, 0, 70)
        {
            if (f[i][g] == 0)
                continue;
            f[i + 1][g] = (f[i + 1][g] + f[i][g]) % MOD;
            f[i + 1][__gcd(g, a[i + 1])] = (f[i + 1][__gcd(g, a[i + 1])] + f[i][g]) % MOD;
        }
        ll ans = 0;
        FOR(g, 1, 70) { ans = (ans + 1ll * g * f[n][g]) % MOD; }
        cout << ans << endl;
    }
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}