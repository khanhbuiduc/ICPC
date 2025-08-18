#include <bits/stdc++.h>

using namespace std;
#define NAME "merger_seg."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
typedef tuple<int, bool, int> tibi;
int n, a, b, c, m, pv = 0, ans = 0;
int main()
{
    fi >> n;
    vector<tibi> x(2 * n);
    vector<bool> flg(n, 0);
    for (int i = 0; i < n; i++)
    {
        fi >> a >> b;
        x[2 * i] = {a, 0, i};
        x[2 * i + 1] = {b, 1, i};
    }
    sort(x.begin(), x.end());
    vector<int> v(n);

    for (int i = 0; i < 2 * n; i++)
    {
        tie(a, c, m) = x[i];

        if (c == 0)
            v[pv++] = m;
        else
        {
            if (flg[m] == 0)
            {
                for (int j = 0; j < pv; ++j)
                {
                    flg[v[j]] = true;
                }
                flg[m] = true;
                ++ans;
                pv = 0;
            }
        }
    }
    fo << ans << endl;
    return 0;
}