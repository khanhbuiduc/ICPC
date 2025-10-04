#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
ll a, b, mod;

ll fib(long long x)
{
    if (x == 0)
        return 0 % mod;
    if (x == 1)
        return 1 % mod;
    ll f0 = 0, f1 = 1, f2 = 1;
    for (long long i = 2; i <= x; i++)
    {
        f2 = (f0 + f1) % mod;
        f0 = f1;
        f1 = f2;
    }
    return f2 % mod;
}
ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> a >> b >> mod;
    ll g = gcd(a, b);
    cout << fib(g);
}