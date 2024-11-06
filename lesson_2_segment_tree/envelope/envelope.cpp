#include <bits/stdc++.h>
using namespace std;
ifstream fi("input");
ofstream fo("output");
int64_t solve(int64_t n, int64_t m, int64_t h, int64_t w)
{
    int64_t ans = 0;
    while (h < n)
    {
        ans++, h <<= 1;
    }
    while (w < m)
    {
        ans++, w <<= 1;
    }

    return ans;
}
int main()
{
    int n, m, h, w;
    fi >> n >> m >> h >> w;
    fo << min(solve(n, m, h, w), solve(m, n, h, w));
}