#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("museum.inp", "r", stdin);
    freopen("museum.out", "w", stdout);
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int d1 = abs(x1 - x2) + abs(y1 - y2);
    int d2 = abs(x1 - x3) + abs(y1 - y3);
    int d3 = abs(x3 - x2) + abs(y3 - y2);
    float ans = (d1 + d2 + d3) / 2;
    cout << ans;
}