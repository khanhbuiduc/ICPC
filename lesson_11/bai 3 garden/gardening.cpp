#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("gardening.inp", "r", stdin);
    freopen("gardening.out", "w", stdout);
    int n;
    cin >> n;
    int res = 0;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++)
    {
        res = max(res, a[i] + i);
    }
    cout << res;
}