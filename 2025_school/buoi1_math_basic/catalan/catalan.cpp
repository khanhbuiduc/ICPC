#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = b; i <= (_b); i++)
typedef long long ll;
int mod = 1'000'000'007;
ll powmod(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}
ll fac(int n)
{
    ll F = 1;
    FOR(i, 2, n)
    {
        (F *= i) %= mod;
    }
    return F;
}
ll modinv(ll a)
{
    return powmod(a, mod - 2);
}

ll catalan(int n)
{
    ll C = (((fac(2 * n) * modinv(fac(n + 1))) % mod) * modinv(fac(n)) % mod);
    return C;
}
int main()
{
    int n;
    cin >> n;
    cout << catalan(n) << endl;
}
// n<100'000'000