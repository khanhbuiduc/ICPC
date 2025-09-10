#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll MOD_power(ll a, ll b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << MOD_power(a, b);
}