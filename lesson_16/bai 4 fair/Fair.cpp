#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("fair.inp", "r", stdin);
    freopen("fair.out", "w", stdout);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int64_t &i : a)
        cin >> i;
    sort(a.rbegin(), a.rend());
    int64_t max = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < (i + 1) * a[i])
        {
            max = (i + 1) * a[i];
            l = i + 1;
            r = a[i];
        }
    }
    cout << l << " " << r;
}