// Stones
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("ans.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int64_t> s(n), p(n);
    for (int64_t &i : s)
        cin >> i;
    for (int64_t &i : p)
        cin >> i;

    int64_t g = 0;
    for (int64_t i : p)
        g = gcd(g, i);
    for (int64_t &i : p)
        i /= g;

    auto Eval = [&](int64_t x)
    {
        int64_t ret = 0;
        for (int i = 0; i < n; i++)
            ret += llabs(s[i] - x * p[i]);
        return ret;
    };

    int64_t low = 1, high = (int64_t)1e9;
    while (low < high)
    {
        int64_t mid = (low + high) >> 1;
        if (Eval(mid) > Eval(mid + 1))
            low = mid + 1;
        else
            high = mid;
    }

    cout << Eval(low) << '\n';
    return 0;
}
