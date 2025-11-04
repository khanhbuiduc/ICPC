#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
ll powerMod(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            (res *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    ll ans = 0;
    (ans += powerMod(2, n)) %= mod;
    if (n % 3 == 2)
    {
        int k = n / 3;
        (ans = ans - powerMod(2, k + 1) + mod) %= mod;
    }
    cout << ans;
}
/*
tòa nhà có n phần:
ô thứ i có ai là số bẫy ở ô i-1, i, i+1
=> có bao nhiêu cách đặt bẫy thỏa mãn

x[i] = 1 0 1 0 1 0
a[i] = 1 2 1 2 1 1
n = 5
---
x1 + x2 = a1
x1 + x2 + x3 = a2

x4 + x5 = a4 - a3
x4 + x5 + x6 = a5

x5 + x6 = a6
-------nếu n%3 dư 1 hoặc n%3 dư 0-----------------
=> nếu n%3 dư 1 hoặc n%3 dư 0
x1 x2 x3 x4 x5 x6 => tính đc x3,x6 và x4,x1
x1 x2 x3 x4 x5 x6 x7 => tính đc x3,x6 và x5,x2
=> số cách: 2^n
--------------- nếu x%3 dư 2----------------------
=> chỉ tính đc x[i]: với i%3==0
    0 1 x 1 0 x 0 1
    1 0 x 0 1 x 1 0
=> cho cùng a[i] ở mọi vị trí.
    1 1 x 0 1 x 0 0
=> uniqui a[i]
---
=> số cách: 2^n - 2^(k+1)
--------------------------------------------
*/