#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    int a, b, m, t;
    string s = "";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> m;
        (b - a) % (m + 1) ? cout << "R" : cout << "B";
    }
}