#include <bits/stdc++.h>
using namespace std;
int x, y, a, b;
bool check(int i)
{
    if (a == b)
        return (long long)i * a <= min(x, y);

    long long v = (x - 1ll * i * a) / (b - a);
    long long u = (y - 1ll * i * a) / (b - a);

    if (v < 0 || u < 0)
        return false;
    return (u + v >= i);
}
void binary_search_on_answer()
{
    int li = 0, hi = min(x, y) / min(a, b);
    int ans = 0;
    while (li <= hi)
    {
        int mid = (li + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            li = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> a >> b;
        if (a > b)
        {
            swap(a, b);
            swap(x, y);
        }
        binary_search_on_answer();
    }
}