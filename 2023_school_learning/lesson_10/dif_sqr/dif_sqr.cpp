#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    freopen("dif_sqr.inp", "r", stdin);
    freopen("dif_sqr.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    int n;
    cin >> n;
    if (n == 1 || n == 2 || n == 4)
        cout << "No";
    else if (n & 1)
    {
        x = (n + 1) / 2;
        y = (n - 1) / 2;
        cout << "yes\n"
             << x << " " << y;
    }
    else if (n % 4)
        cout << "No";
    else
    {
        x = (n + 4) / 4;
        y = (n - 4) / 4;
        cout << "yes\n"
             << x << " " << y;
    }
}