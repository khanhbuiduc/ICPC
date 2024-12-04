#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("fruit.inp", "r", stdin);
    freopen("fruit.out", "w", stdout);
    int n;
    cin >> n;
    __int128_t res = (__int128_t)(n + (n + 1) * n / 2);
    string s = "";
    while (res > 0)
    {
        s = (char)(res % 10 + 48) + s;
        res /= 10;
    }
    cout << s;
}