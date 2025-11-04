// 7 white cells
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int64_t n, k;
    cin >> n >> k;

    if (n == 1)
    {
        cout << ((k > 0) ? 6 : 0);
        return 0;
    }

    if (k <= 8)
    {
        cout << 3 * k;
        return 0;
    }

    if (k > 8 && n == 2)
    {
        cout << 24;
        return 0;
    }

    if (k <= 8 + 12 * (n - 2) && n > 2)
    {
        cout << 24 + (k - 8) * 2;
        return 0;
    }

    if (k <= 8 + 12 * (n - 2) + 6 * (n - 2) * (n - 2) && n > 2)
    {
        cout << 24 + 24 * (n - 2) + k - 12 * (n - 2) - 8;
        return 0;
    }

    cout << 6 * n * n;
    return 0;
}
