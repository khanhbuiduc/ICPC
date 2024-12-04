#include <bits/stdc++.h>
using namespace std;
#define inf 1'000'000
int main()
{
    freopen("fractional.inp", "r", stdin);
    freopen("fractional.out", "w", stdout);
    int n, c, b = 1; // n chữ số
    cin >> n >> c;
    // chuyển n thành số;
    while (n--)
        b *= 10; // b=2^a*5^b
    while (!(b % 2) && !(c % 2))
    {
        b /= 2;
        c /= 2;
    };
    while (!(b % 5) && !(c % 5))
    {
        b /= 5;
        c /= 5;
    };
    if (b < inf && c < inf && c > 0)
        cout << "YES" << "\n"
             << c << " " << b;
    else
        cout << "NO";
}