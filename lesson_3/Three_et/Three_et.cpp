#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int64_t n, t1, t2, t3, t_pair, t_all, ans;
    cin >> n >> t1 >> t2 >> t3;
    t_pair = t1 + max(t1, t2);
    if (t2 >= 2 * t1)
    {
        cout << t1 + t2 + t3 + (n - 1) * max(t2, t3);
        exit(0);
    }
    if (t1 == t2 && (t3 >= 2 * t1))
    {
        cout << 2 * t1 + n * t3;
        exit(0);
    }
    if (t1 == t2 && (t3 <= t1))
    {
        cout << 2 * n * t1 + t3;
        exit(0);
    }
    if (t3 >= t_pair)
    {
        cout << t_pair + n * t3;
        exit(0);
    }
    if (t1 == 2 && (t2 == 1))
    {
        cout << t3 + 4 * n;
        exit(0);
    }
    if (t1 == 2 && (t2 == 3))
        cout << t3 + 1 + 4 * n;
}