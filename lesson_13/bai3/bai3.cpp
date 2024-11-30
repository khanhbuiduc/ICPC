#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bai3.inp", "r", stdin);
    freopen("bai3.out", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
    int a, b;
    if (s == m * n)
    {
        cout << "0";
        return 0;
    }
    else if (s % n == 0 && s % m == 0)
    {
        cout << "1";
        return 0;
    }
    else
    {
        for (int a = 0; a < n; a++)
        {
            b = (s - (n - a) * m) % (a - (n - a));
            if (b == 0)
                cout << "2";
            return 0;
        }
    }

    cout << "3";
}