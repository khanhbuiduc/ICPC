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

    while (n / k >= 9) // tổ hợp các chập 3 với q>2 là kết quả cần tìm
    {
        flg = true;
        //
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
        // tính số lượng các số tham gia tạo nhóm 3 kì diệu
        q = floor(sqrt(n / k)) + 1; // k=1: 1,4,9,16,25; k=2: 2, 8,18; k=3:3,13,27;

        if (q * q > n / k)
        {
            --q;
        }
        // tính tổ hợp chập 3 của q
        ans += static_cast<int64_t>(q) * (q - 1) * (q - 2) / 6;
        ++k;
    }

    fo << ans;
}
