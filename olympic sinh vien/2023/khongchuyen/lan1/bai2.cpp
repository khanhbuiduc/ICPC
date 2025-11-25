#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int a[100'005];
int n, m;
ll cal_cost(ll a, ll b)
{
    ll ans = (b - a + m) % m;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, n)
    cin >> a[i];
    // case 2: n,m <= 1000;
    if (n <= 1000 && m <= 1000)
    {
        ll min_cost = 1e18;
        FOR(x, 1, m - 1)
        {
            ll cost = 0;
            FOR(i, 2, n)
            {
                cost += min(cal_cost(a[i - 1], a[i]), cal_cost(x, a[i]) + 1);
            }
            min_cost = min(cost, min_cost);
        }
        cout << min_cost;
        return 0;
    }
    // case 1:
    ll maxlen = -1;
    ll sum = 0;
    FOR(i, 2, n)
    {
        ll len = cal_cost(a[i - 1], a[i]);
        sum += len;
        maxlen = max(len, maxlen);
    }
    cout << (ll)(sum - maxlen + 1);
}