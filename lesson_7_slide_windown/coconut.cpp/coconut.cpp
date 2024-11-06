#include <bits/stdc++.h>

using namespace std;
#define NAME "coconut."
ifstream fi("inp");
ofstream fo("out");
int main()
{
    int n, k;
    fi >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        fi >> i;
    int l, r;
    l = a[0];
    r = a[0];
    fo << "1 ";
    for (int i = 1; i < n; i++)
    {
        if (l - k <= a[i] && a[i] <= r + k)
        {
            fo << "1 ";
            l = min(l, a[i]);
            r = max(r, a[i]);
        }
        else
            fo << "0 ";
    }
}