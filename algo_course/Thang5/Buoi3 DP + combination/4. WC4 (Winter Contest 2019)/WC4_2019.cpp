#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAXN = 1005;
ll f[MAXN];
int n;
string s;
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

ll C(ll n, ll k)
{
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}

void pre_caculator()
{
    fact[0] = 1;
    FOR(i, 1, MAXN - 1)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAXN - 1] = MOD_power(fact[MAXN - 1], MOD - 2);
    FORD(i, MAXN - 2, 0)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_caculator();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 0, n)
        f[i] = 0;
        f[0] = 1;

        FOR(i, 1, n)
        FOR(j, 1, i)
        {
            f[i] = (f[i] + C(i - 1, j - 1) * f[i - j]) % MOD;
        }
        cout << f[n] << endl;
    }
    return 0;
}

/*
WC4 (Winter Contest 2019)

Cho số nguyên dương N, xét tập hợp gồm N số tự nhiên đầu tiên. Hãy đếm có bao nhiêu cách chia tập hợp sao cho mỗi phần tử phải ở trong đúng 1 tập hợp
N- 3

{1,2,3}
{1,2}, {3}
{1,3}, {2}
{2, 3}, {1}
{1}, {2}, {3}
-------------------
f[i]: là số tập hợp xét i số đầu tiên
f[1] = 1; {1}
f[2] = 2; {1}, {2}; f[2] = f[1]*  + 1
f[3] = 5; f[1] + số tập hợp f[2]
----------------------------------------
giả sử nhóm cuối có j phần tử.
f[i] = f[i] + C(j,i) * f[i - j] với j: 1->i
    vd: {1,2}, {3}
        {1},{2},{3}
cách này đếm bị trùng
    vd: {1, 3}, {2}
        {1}, {3}, {2}
----------------------------------------
pp chuẩn:

gọi  f[i] là số tập hợp khi xét i số đầu tiên

khi xét f[i]: giả sử nhóm cuối cùng có j phần tử. nhóm cuối chứa i

NHÓM J PHẦN TỬ:  {i,?,?,?} => C(j-1, i-1);

f[i] += C(j-1,i-1) * f[i-j];
*/