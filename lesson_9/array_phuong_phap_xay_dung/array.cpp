#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("array.inp", "r", stdin);
    freopen("array.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n, 0);
    int val = l | 1;
    int i = 0;

    while (val <= r)
    {
        a[i++] = val;
        val += 2;
        if (val <= r)
            a[i++] = val;
        val++;

        if (val <= r)
            if (!(val % 3))
                a[i++] = (val - 2) % 5 ? val + 2 : val - 2;
            else
                a[i++] = val;
        val++;
    }
    //
    int b1 = a[i - 3], b2 = a[i - 2], b3 = a[i - 1];
    while (i < n)
    {
        a[i++] = b1;
        val++;
        if (i < n)
        {
            a[i++] = b2;
            val++;
        }
        if (i < n)
        {
            a[i++] = b3;
            val++;
        }
    }
    for (int num : a)
        cout << num << " ";
}