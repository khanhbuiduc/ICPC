#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define Mod 68'718'952'446 // 10^11 ll
typedef pair<int, int> pii;
typedef long long ll;
int powerMod(int x, int n, int m)
{
    ll ans = 1;
    ll base = x % m;
    while (n)
    {
        if (n & 1)
            ans = (ans * base) % m;
        base = (base * base) % m;
        n >>= 1;
    }
    return (int)ans;
}
int cal(int x, int n, int m)
{
    if (n == 0)
        return 1;
    if ((n & 1) == 0)
        return (cal(x, n - 1, m) + powerMod(x, n, m)) % m;
    else
    {
        return (1ll * cal(x, n / 2, m) * (1 + powerMod(x, n / 2 + 1, m))) % m;
    }
}
int main()
{
    int t;
    int x, n, m;
    cin >> t;
    while (t--)
    {
        cin >> x >> n >> m;
        cout << cal(x, n, m) << endl;
    }
}