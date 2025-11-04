#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
typedef long long ll;

int n;
ll s[100005], p[100005];

// Dùng double để tránh overflow
ll calc(ll k)
{
    ll total = 0;
    FOR(i, 1, n)
    total += abs(s[i] - k * p[i]);
    return total;
}
// hay cách dùng bs thay cho ts
ll bs()
{
    ll lo = 0, hi = 1e9;
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        if (calc(mid) >= calc(mid + 1))
        {
            lo = mid + 1;
            ans = lo;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return calc(ans);
}
ll ternary_search()
{
    double lo = 0, hi = 1e9;

    // Ternary search với double
    for (int iter = 0; iter < 100; iter++) // 100 lần đủ cho độ chính xác
    {
        double mid1 = lo + (hi - lo) / 3;
        double mid2 = hi - (hi - lo) / 3;

        if (calc(mid1) > calc(mid2))
        {
            lo = mid1;
        }
        else
        {
            hi = mid2;
        }
    }

    // // Tìm k tối ưu (làm tròn)
    ll k_opt = (ll)round((lo));

    // Kiểm tra các giá trị xung quanh k_opt
    ll best = calc(k_opt);
    for (ll k = max(0LL, k_opt - 1); k <= k_opt + 1; k++)
    {
        best = min(best, (ll)calc(k));
    }
    return best;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, 1, n)
    cin >> s[i];
    FOR(i, 1, n)
    cin >> p[i];
    cout << bs();
}

/*
f(k)
60 |
   | \            /
30 |  \         /
   |    \     /
 0 |     \  /
   +----------------------> k
*/