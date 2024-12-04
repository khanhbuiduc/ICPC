#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bai1.inp", "r", stdin);
    freopen("bai1.out", "w", stdout);
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    int d2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    int d3 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
    if (d1 > d2)
    {
        d1 > d3 ? cout << x1 << " " << y1 << " " << x2 << " " << y2 : cout << x3 << " " << y3 << " " << x2 << " " << y2;
    }
    else
    {
        d2 > d3 ? cout << x1 << " " << y1 << " " << x3 << " " << y3 : cout << x3 << " " << y3 << " " << x2 << " " << y2;
    }
}