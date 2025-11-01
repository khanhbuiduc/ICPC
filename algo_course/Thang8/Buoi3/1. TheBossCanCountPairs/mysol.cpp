#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int t, n;
pii num[200'005];
ll ans = 0;
void initial()
{
    cin >> n;
    FOR(i, 1, n) { cin >> num[i].ff; }
    FOR(i, 1, n) { cin >> num[i].ss; }
    sort(num + 1, num + n + 1);
    // reset
    ans = 0;
}
void solve()
{
    for (int aj = 1; aj * aj <= 2 * n; aj++)
    {
        vector<int> cnt(n + 1, 0); // cnt[bj] với mỗi aj
        FOR(i, 1, n)
        {
            auto [ai, bi] = num[i];
            int bj = ai * aj - bi;
            if (1 <= bj && bj <= n)
                ans += cnt[bj];
            if (ai == aj)
            {
                cnt[bi]++;
            }
        }
    }
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
        cout << ans << endl;
    }
    return 0;
}

/*
    ai * aj=bi + bj
cnt = 0;
 duyệt ai : a[1..n]
    duyệt bi: b[1..n]
        check thỏa mãn điểu kiện thì cnt++
O(n^2)
---
ai⋅aj=bi+bj
mà bi, bj<=n
giả sử: aj < ai => aj < căn n;

duyệt aj: 1->căn n;//
    cnt[x] số lượng vị  trí b[j] = x với aj
    duyệt i: 1->n
        có bao nhiêu bj = aj*ai - bi;
            ans += cnt[aj*ai - bi] ;
        nếu bj = aj*ai - bi thuộc [1..n] thỏa mãn.
            thì cnt[b[i]]++
*/