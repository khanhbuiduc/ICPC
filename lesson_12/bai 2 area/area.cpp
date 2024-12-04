#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("area.inp", "r", stdin);
    freopen("area.out", "w", stdout);
    int c, h;
    cin >> c >> h;
    if (2 * h <= c)
        cout << (float)(c * h) / 2;
    else
        cout << "-1";
}