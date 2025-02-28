#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007;

ll modAdd(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll modSub(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll modMul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
// Faster modular inverse when MOD is prime using Fermat's little theorem
// Time complexity: O(log(MOD))
ll modInverse(ll a)
{
    return modPow(a, MOD - 2); // Using a^(p-1) ≡ 1 (mod p)
}
ll modDiv(ll a, ll b)
{
    return modMul(a, modInverse(b));
}

ll modPow(ll a, ll b)
{
    ll result = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

int main()
{
    freopen("mod.inp", "r", stdin);
    freopen("mod.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        cout << "For a=" << a << ", b=" << b << ":\n";
        cout << "(a + b) % MOD = " << modAdd(a, b) << "\n";
        cout << "(a - b) % MOD = " << modSub(a, b) << "\n";
        cout << "(a * b) % MOD = " << modMul(a, b) << "\n";
        cout << "(a / b) % MOD = " << modDiv(a, b) << "\n";
        cout << "pow(a, b) % MOD = " << modPow(a, b) << "\n";
        cout << "inverse(a) % MOD = " << modInverse(a) << "\n\n";
    }
    return 0;
}
