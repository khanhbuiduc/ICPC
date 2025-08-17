#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define MAXN 100005
#define MOD 987654321
using namespace std;
typedef long long ll;
ll n; // n<10^18
ll cnt_diagonal()
{
    __int128_t num1 = 1;
    ll res = (ll)((num1 * n * (n - 3) / 2) % MOD);
    return res;
}
ll cnt_intersetion()
{
    ll n1 = n, n2 = n - 1, n3 = n - 2, n4 = n - 3;
    int deno = 24;
    int g1 = gcd(deno, n1);
    deno /= g1;
    n1 /= g1;
    ///
    int g2 = gcd(deno, n2);
    deno /= g2;
    n2 /= g2;
    ///
    int g3 = gcd(deno, n3);
    deno /= g3;
    n3 /= g3;
    ///
    int g4 = gcd(deno, n4);
    deno /= g4;
    n4 /= g4;
    __int128_t num1 = 1;
    ll res = (ll)((num1 * (n1 % MOD) * (n2 % MOD) * (n3 % MOD) * (n4 % MOD)) % MOD);
    return res;
}
int main()
{
    cin >> n;
    ll ans = (cnt_diagonal() + cnt_intersetion() + 1) % MOD;
    cout << ans;
}

// đường chéo: N * (n-3) / 2
// giao 2 đường chéo: C(4,n) = n * (n-1) * (n-2) * (n-3)