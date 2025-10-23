#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int a[200'005];
int n, k;
void initial()
{
    cin >> n >> k;
    FOR(i, 1, n) { cin >> a[i]; }
}
void solve()
{
    // đếm:
    int ans = 0;
    FORD(bit, 30, 0)
    {
        int cnt = 0;
        FOR(i, 1, n)
        {
            if (a[i] & (1 << bit))
            {
                cnt++;
            }
        }
        if (cnt + k >= n)
        {
            ans += (1 << bit);
            if (cnt < n)
            {
                k -= (n - cnt);
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        initial();
        solve();
    }
}
// cho a[1..n]: ai<2^31, n<200k, k <10^9
/*
in ra AND(a[1]...a[n]) có k biến đổi đặt bit j của a[i] thành 1. j: 0->30
vd:
3 2
2 1 1

---
n = 3, k = 3
cnt=[0,0,0,0,0,0,0,1,2]

cnt->num
    cnt[i]>=n, ans + (1<<i)
*/