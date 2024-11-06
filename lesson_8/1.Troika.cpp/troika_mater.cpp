#include <bits/stdc++.h>
using namespace std;
#define NAME "troika."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
int64_t n, k, p, ans = 0, q;
bool flg;
set<int64_t> s; // danh sách số chính phương từ 1 đến k
int main()
{
    fi >> n;
    k = 1;
    p = 2;
    s.insert(p * p);

    while (n / k >= 9) // q>3
    {
        flg = true;

        if (k == p * p)
        {
            ++k;
            ++p;
            s.insert(p * p);
            continue;
        }

        for (int t : s) //
        {
            if (k % t == 0)
            {
                ++k;
                flg = false;
                break;
            }
        }

        if (!flg)
            continue;

        q = floor(sqrt(n / k)) + 1; // k=1: 1,4,9,16,25; k=2: 2, 8,18; k=3:3,13,27;

        if (q * q > n / k)
        {
            --q;
        }

        ans += static_cast<int64_t>(q) * (q - 1) * (q - 2) / 6; // tính số lượng
        ++k;
    }

    fo << ans;
}
