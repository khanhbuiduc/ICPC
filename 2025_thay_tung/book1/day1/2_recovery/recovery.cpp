#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
int a[200'005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, c;
    cin >> n >> c >> k;
    FOR(i, 1, n)
    cin >> a[i];

    sort(a + 1, a + n + 1);

    int l = 1, r = 0;
    ll ans = 1e18;
    ll sum = 0;

    FOR(lf, 1, c - k + 1)
    {
        int rf = lf + k - 1;

        if (rf > c)
            break;

        while (l <= n && a[l] < lf)
        {
            sum -= a[l];
            l++;
        }

        while (r + 1 <= n && a[r + 1] <= rf)
        {
            r++;
            sum += a[r];
        }

        ans = min(ans, sum);
    }

    cout << ans;
}
/*
có n đối tượng, đối tượng i có chi phí cost[i].
khôi phục các đối tượng có cost trong khoảng [lf..rf]
với rf-lf+1 = k.
0<lf, rf<=c;
tổng kinh phí nhỏ nhất

n=5 10 6
1 3 5 2 4
---
output: 5
*/