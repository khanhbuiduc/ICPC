#include <bits/stdc++.h>

using namespace std;
#define NAME "covering."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");

typedef tuple<int, bool, int> tibi;
// tọa độ, loại(đầu đoạn,cuối đoạn), vị trí
int c, t, si;

int n, a, b;
int pv = 0, ans = 0;
void covering(vector<tibi> &x)
{
    vector<bool> flg(n, 0);
    sort(x.begin(), x.end());
    vector<int> v(n); // đoạn đang được sử dụng

    for (int i = 0; i < 2 * n; i++)
    {
        auto [c, t, si] = x[i];
        // nếu là đầu đoạn thêm vào v
        if (t == 0)
            v[pv++] = si;
        else // nếu là cuối đoạn
        {
            if (flg[si] == 0) // nếu chưa được phủ
            {
                // đánh dấu đã được phủ ở tất cả các đoạn trong v và cả điểm hiện tại
                for (int j = 0; j < pv; ++j)
                    flg[v[j]] = true;
                // flg[si] = true; thừa
                ++ans;
                pv = 0; // Reset active segment pointer
            }
        }
    }
}
int main()
{
    fi >> n;
    vector<tibi> x(2 * n);
    for (int i = 0; i < n; i++)
    {
        fi >> a >> b;
        x[2 * i] = {a, 0, i};
        x[2 * i + 1] = {b, 1, i};
    }
    covering(x);
    fo << ans << endl;
    return 0;
}