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
ll cal(ll n, ll k)
{
    return C(n + k - 1, k - 1);
}
int main()
{
    pre_caculator();
    int a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;
    //  có k dãy 0 => có k-1,k,k+1 dãy 1;
    int max_k0 = a0 / b0;
    int max_k1 = a1 / b1;
    ll ans = 0;
    FOR(k0, 1, max_k0)
    {
        FOR(i, -1, 1)
        {
            int k1 = k0 + i;
            if (k1 <= 0 || k1 >= max_k1 + 1)
                continue;
            ll cur_cal = cal(a0 - k0 * b0, k0 + 1) * cal(a1 - k1 * b1, k1 + 1) % MOD;
            if (k0 == k1)
                cur_cal = (cur_cal * 2) % MOD;
            ans = (ans + cur_cal) % MOD;
        }
    }
    cout << ans;
}

/*
s  = 1100001111000 = [11][0000][1111][000]
có tối đa: a0 số 0, a1 số 1
trong dãy toàn 0 có tối thiểu: b0 số 0, b1 số 1

có k dãy 0 => có k-1,k,k+1 dãy 1;
x0[0] + x0[1] + x0[2] + ... x0[k]  <= a0  với b0 <= x[0][i]
x0[0] + x0[1] + x0[2] + ... x0[k] - k*b0  <= a0 - k*b0

đặt u0[i]  = x0[i] - b0;

u0[0] + u0[1] + u0[2] + ... u0[k] <= a0 - k*b0  với u0[k] > 0

chia a1 - b1 * k cái kẹo cho k bạn. mỗi bạn có ít nhất 0 cái kẹo
-----
// lỗi: thiếu khi k0=k1 có 2 cách xắp xếp
*/