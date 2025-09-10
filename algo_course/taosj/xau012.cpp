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
#define MOD 1000000007
typedef long long ll;
const int MAXN = 100'005;
ll fact[MAXN], inv_fact[MAXN], power2[MAXN];
ll MOD_power(ll a, ll b)
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
void pre_caculator()
{
    fact[0] = 1;
    FOR(i, 1, MAXN - 1) { fact[i] = (fact[i - 1] * i) % MOD; }

    inv_fact[MAXN - 1] = MOD_power(fact[MAXN - 1], MOD - 2);
    FORD(i, MAXN - 2, 0) { inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD; }
    // power 2
    power2[0] = 1;
    FOR(i, 1, MAXN) { power2[i] = ((power2[i - 1] * 2) % MOD); };
}
ll C(ll n, ll k)
{
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    pre_caculator();
    int n;
    while (cin >> n)
    {
        ll ans = 0;
        FOR(i, 0, (n + 1) / 2)
        {
            (ans += (C(n - i + 1, i) * power2[n - i])) %= MOD;
            // cout << ans << ' ';
        }
        cout << endl;
        cout << ans;
    }
}

//
