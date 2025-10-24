#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;
__int128_t num1 = 1;
ll sum(ll l, ll r)
{
    if (l > r)
        return 0;
    ll right = (num1 * r * (r + 1) / 2) % MOD;
    ll left = (num1 * (l - 1) * (l) / 2) % MOD;
    return (right - left);
}

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll sqrtN = sqrt(n);

    for (int i = 1; i <= sqrtN; i++)
    {
        // đóng góp của số nhỏ hơn căn n
        ans = (ans + (i * (n / i)) % MOD) % MOD;
        // đóng góp của số lớn hơn căn n
        ll l = max(sqrtN + 1, n / (i + 1) + 1);
        ll r = n / i;
        ans = (ans + (i * sum(l, r))) % MOD;
    }

    cout << ans << endl;
    return 0;
}