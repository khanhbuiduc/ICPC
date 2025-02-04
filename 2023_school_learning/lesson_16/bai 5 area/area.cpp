#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("area.inp", "r", stdin);
    freopen("area.out", "w", stdout);
    vector<int> a(4);
    for (int &i : a)
    {
        cin >> i;
    }
    sort(a.begin(), a.end());
    cout << a[0] * a[2];
}