#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        while (l > 0 || r > 0)
        {
            ans += (r - l);
            l /= 10;
            r /= 10;
        }
        cout << ans << endl;
    }
}

/*
1000000000

1

---------
hàng đơn vị thay đổi: 999'999'999 + 100'000'000 + 10'000'000 + 10'000'000 +...+1
*/