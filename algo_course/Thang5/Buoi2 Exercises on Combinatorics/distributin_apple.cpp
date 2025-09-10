#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;
__int128_t num1 = 1;
const int MAXN = 2000005;
ll fact[MAXN], inv_fact[MAXN];
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
    FOR(i, 1, MAXN - 1)
    fact[i] = (fact[i - 1] * i) % MOD;
    inv_fact[MAXN - 1] = MOD_power(fact[MAXN - 1], MOD - 2);
    FORD(i, MAXN - 2, 0)
    inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}
ll C(ll n, ll k)
{
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}
int main()
{
    pre_caculator();
    int n, m;
    cin >> n >> m;
    cout << C(n + m - 1, n - 1);
}