#include <bits/stdc++.h>
using namespace std;
#define NAME "modular."

ifstream fi(NAME "inp");
ofstream fo(NAME "out");
// Modular Exponentiation (Power in Modular Aritmetic) (x^y% mod )

//(x*y)%mod=(x%mod*y%mod)%mod tương tự với cách phép +,-,*,/
#define ll long long
ll Modular(ll x, ll y, int mod)
{
    int res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y % 2)
            res = (res * x) % mod;
        y = y / 2;
        x = (x * x) % mod;
    }
    return x;
}

int main()
{
    long long x, y, mod, res = 1;
    fi >> x >> y >> mod;

    fo << Modular(x, y, mod) << endl;

    return 0;
}