#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bai13.inp", "r", stdin);
    freopen("bai13.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    // int a = (a[0] + a[1] - a.back() - a[0]);
    int ans = (a[0] + a[1] - (a.back() - a[0])) - 1;
    if (ans <= 0)
        cout << 0;
    else
        cout << ans;
}