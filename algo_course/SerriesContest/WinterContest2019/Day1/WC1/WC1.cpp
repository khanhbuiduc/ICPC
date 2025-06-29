#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define Mod 68'718'952'446 // 10^11 ll
typedef pair<int, int> pii;
typedef long long ll;
int n;
int a[100'005];
ll prefix[100'005], suffix[100'005];
ll mulMod(ll x, ll y)
{
    __int128_t res = (x * y) % Mod;
    return (ll)res;
}
int main()
{
    freopen("WC1.INP", "r", stdin);
    freopen("WC1.OUT", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        prefix[0] = suffix[n + 1] = 1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            prefix[i] = mulMod(prefix[i - 1], a[i]);
        for (int i = n; i >= 1; i--)
            suffix[i] = mulMod(suffix[i + 1], a[i]);
        for (int i = 1; i <= n; i++)
        {
            cout << mulMod(prefix[i - 1], suffix[i + 1]) << " ";
        }
        cout << endl;
    }
}