#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
using namespace std;
/// template
typedef long long ll;
int n;
ll p[100005], x[100005];
const int MOD = 1000000007;
ll pre_product[100005], suf_product[100005]; //(x1 + 1)(x2 + 1)...(xn + 1)
void initial()
{
    cin >> n;
    FOR(i, 1, n)
    cin >> p[i] >> x[i];
    pre_product[0] = suf_product[n + 1] = 1;
    FOR(i, 1, n) { pre_product[i] = (pre_product[i - 1] * (x[i] + 1)) % (MOD - 1); }
    FORD(i, n, 1) { suf_product[i] = (suf_product[i + 1] * (x[i] + 1)) % (MOD - 1); }
}
ll pow_mod(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll inverse_mod(int a)
{
    return pow_mod(a, MOD - 2);
}
ll cal_sum(ll x)
{
    return (x * (x + 1) / 2) % (MOD - 1);
}
void solve()
{
    // num of divisors (x1+1)*(x2+1)*(x3+1)*(x4+1)*(x5+1)
    ll num = 1;
    FOR(i, 1, n)
    {
        (num *= (x[i] + 1)) %= (MOD);
    }
    cout << num << ' ';
    // sum of divisors Sn = (1-(pi^(xi+1))/ (1-pi)
    ll sum = 1;

    FOR(i, 1, n)
    {
        ll numerator = (pow_mod(p[i], x[i] + 1) - 1) % MOD;
        ll denominator = inverse_mod(p[i] - 1);
        ll Si = (numerator * denominator) % MOD;
        sum = (sum * Si) % MOD;
    }
    cout << sum << ' ';
    // product of divisors
    ll product = 1;
    FOR(i, 1, n)
    {
        ll power = 1;
        (power *= pre_product[i - 1]) %= (MOD - 1);
        (power *= suf_product[i + 1]) %= (MOD - 1);
        (power *= cal_sum(x[i])) %= (MOD - 1);
        ll product_pi = pow_mod(p[i], power);
        (product *= product_pi) %= MOD;
    }
    cout << product;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    initial();
    solve();
    return 0;
}