#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int t, n;
int a[200'005];
int cnt[31];
void initial()
{
    cin >> n;
    FOR(i, 1, n) { cin >> a[i]; }
    // reset cnt;
    FOR(i, 0, 30) { cnt[i] = 0; }
}
void solve()
{
    ll ans = 0;
    // chỉ quan tâm bit 1 đầu tiên.
    FOR(i, 1, n)
    {
        FORD(bit, 30, 0)
        {
            if (a[i] & (1 << bit))
            {
                cnt[bit]++;
                break;
            }
        }
    }
    FOR(i, 0, 30)
    {
        if (cnt[i] >= 2)
        {
            ans += (1ll * cnt[i] * (cnt[i] - 1) / 2);
        }
    }
    cout << ans << endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        initial();
        solve();
    }
}
/*
1&1 = 1
1&0 hay 0&1 = 0
0&0 = 0
---
1^1 = 0
0^0 = 0
1^0 hay 0^1 = 1
------
ai & aj≥ai⊕aj
xét bit 30->0
    nếu ai, aj ở vị trí bit đều bằng 0. continue
    nếu ai, aj ở vị trí bít đều bằng 1. return true
    return false;
*/