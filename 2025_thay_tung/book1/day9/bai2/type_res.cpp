#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
string charactor = "NZQR";
int t_div[4] = {2, 2, 2, 3};
int t_minus[4] = {1, 1, 2, 3};
//
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
ll fact[MAXN], inv_fact[MAXN];
ll powMod(ll a, ll b)
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
void pre_calculator()
{
    fact[0] = 1;
    FOR(i, 1, MAXN - 1)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAXN - 1] = powMod(fact[MAXN - 1], MOD - 2);
    FORD(i, MAXN - 2, 0)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll n, ll k)
{
    if (k > n || k < 0)
        return 0;
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    char a, sign, c;
    cin >> a >> sign >> c;
    int ai, ci;
    FOR(i, 0, 3)
    {
        if (charactor[i] == a)
        {
            ai = i;
        }
        if (charactor[i] == c)
        {
            ci = i;
        }
    }
    int m = max(ai, ci);
    if (sign == '+' || sign == '*')
    {
        cout << charactor[m];
        return 0;
    }
    if (sign == '-')
    {
        cout << charactor[t_minus[m]];
        return 0;
    }
    if (sign == '/')
    {
        cout << charactor[t_div[m]];
        return 0;
    }
}
// NZQR
/*
+,-,*,/

chia: N/Z = Q
a + b = max(a,b)
a * b = max(a,b)
---
N - N = Z
còn lại: (a - b) theo số lớn hơn
---
a / b
nếu không chứa R: Q
nếu chứa R: Z
---

*/