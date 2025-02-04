#include <bits/stdc++.h>

using namespace std;
ifstream fi("input");
ofstream fo("output");
int main()
{
    int n, k, p, q;
    fi >> n >> k >> p >> q;
    n = n % 2 == 1 ? ++n : n;
    int alice = 2 * (p - 1) + q;
    int bob = (alice - k > 0) ? alice - k : alice + k;
    if (bob > n)
    {
        fo << -1;
        return 0;
    }
    int row = (bob + 1) / 2;
    int col = bob % 2 == 0 ? 2 : 1;
    fo << row << " " << col;
}