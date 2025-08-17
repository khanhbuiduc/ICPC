#include <bits/stdc++.h>
using namespace std;
ifstream fi("input");
ofstream fo("output");
int main()
{
    int n, k;
    fi >> n >> k;
    int ans = (2 * n) / (k + 2);
    fo << ans;
}