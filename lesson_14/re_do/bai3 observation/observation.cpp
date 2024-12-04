#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define all(a) begin(a), end(a)
int main()
{
    freopen("observation.inp", "r", stdin);
    freopen("observation.out", "w", stdout);

    // h,w,k: cột, hàng và số camera:
    int w, h, k;
    cin >> h >> w >> k;

    // hàng việc di chuyển hàng và cột là độc lập không ảnh hưởng đến nhau nên ta xử lý hàng và cột độc lập
    vector<int> r(k), c(k);
    for (int i = 0; i < k; i++)
        cin >> r[i] >> c[i];
    auto get = [&](vector<int> x, int h)
    {
        sort(all(x));
        // không cần xét cùng hàng/cột
        x.resize(unique(all(x)) - begin(x));
        k = x.size();
        // tìm khoảng cột/hàng trống lớn nhất
        // độ phủ của hàng/cộtcột:(h-x(i+1)+1)+xi
        int longest = (h - 1) - (x.back() - x[0]) % w;
        int mshift = 0;
        for (int i = 0; i < k - 1; i++)
        {
            // xét cột/hàng xi và x(i+1);

            if ((x[i + 1] - x[i]) - 1 >= longest)
            {
                // (h-x(i+1)+1) là số phép dịxh phải, xi là số phép dịxh trái
                int ms = min(h - x[i + 1] + 1, x[i]);
                if ((x[i + 1] - x[i]) - 1 == longest)
                {
                    mshift = min(mshift, ms);
                }
                else
                    mshift = ms;
                longest = (x[i + 1] - x[i]) - 1;
            }
        }
        return make_pair(h - longest, mshift);
    };
    pii row = get(r, h);
    pii col = get(c, w);
    cout << row.first * col.first << " " << row.second + col.second;
}