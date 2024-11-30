#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("binum.inp", "r", stdin);
    freopen("binum.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b)
        swap(a, b);
    if (b >= c)
        d == 0 ? cout << a - b + c : cout << b - c + 1;
    else if (c > b)
        d == 0 ? cout << c - 1 : cout << a - c + 1;
    else
        d == 0 ? cout << b : cout << "1";
    return 0;
}