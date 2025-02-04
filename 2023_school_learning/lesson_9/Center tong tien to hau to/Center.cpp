#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("center.inp", "r", stdin);
    freopen("center.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int64_t res = INT64_MAX;
    cin >> n;
    vector<int64_t> a(n + 1), p(n + 2, 0), s(n + 2, 0);
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // tổng tiền tố
    p[0] = 0;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        p[i] = p[i] + p[i - 1];
    // tổng hậu tố
    s[n] = 0;
    for (int i = n; i >= 0; i--)
        s[i] = s[i + 1] + a[i];
    for (int i = n; i >= 0; i--)
        s[i] = s[i + 1] + s[i];
    for (int i = 1; i <= n; i++)
    {
        int t = p[i - 1] + s[i + 1];
        if (t < res)
            res = t;
        // res = min(res, p[i - 1] + s[i + 1]);
    }
    cout << res;
}