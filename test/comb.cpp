#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
// 2'000'000'000'000'000'000
const ll mod = 1'000'000'000'000'000'000;
const int modint = 1'000'000'007;
ll a, b;
ll addMod()
{
    return (a % mod + b % mod) % mod;
}
ll mulMod(ll x, ll n)
{
    return ((__int128_t)(x % mod) * (n % mod)) % mod;
}
ll subMod()
{
    return (a % mod - b % mod + mod) % mod;
}
ll powerMod(ll x, ll n)
{
    x %= modint;
    ll ans = 1;
    while (n != 0)
    {
        if ((n & 1) == 1)
            (ans *= x) %= modint;
        (x *= x) %= modint;
        (n >>= 1) %= modint;
    }
    return ans;
}
ll inv(ll b) // 1/b = b^(mod-2)
{
    // b^(mod-1) % mod = 1
    return powerMod(b, mod - 2);
}
ll divMod(ll a, ll b)
{
    // a / b =a * b^(mod - 2)
    // gcd(b,mod) = 1;
    return mulMod(a, inv(b));
}
/*
c(n,k) = n! / (k! * (n-k)!) = n! * invMod(k!) *  invMod((n-k)!)
n < 200'000
precaculator:
    fact[], invf[]
    fact[1] = 1
        fact[i] = (fact[i-1] * i) % mod;
    invf[i] = invMod[fact[i]];
---
invf[n] = invMod[fact[n]]
1/(k-1)! và 1/k!
invf[i] =  (invf[i+1] * i) % mod
-----------------------------------------------------------
c(n,k) = fact[n] * invf[k] *  invf[n-k]

*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> a >> b;
    ll ans = powerMod(a, b);
    cout << ans;
}