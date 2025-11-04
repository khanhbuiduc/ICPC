// Safety
#include <bits/stdc++.h>
using namespace std;
const int M = 1'000'000'007;

int pow2(int p)
{
    int64_t b = 2, r = 1;
    while (p > 0)
    {
        if (p & 1)
            r = r * b % M;
        b = b * b % M;
        p >>= 1;
    }
    return r;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;
    k = n / 3 + 1;
    int ans = pow2(n);
    if (n % 3 == 2)
        ans = (ans - pow2(k) + M) % M;
    cout << ans;
}
