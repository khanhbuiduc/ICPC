#include <bits/stdc++.h>

using namespace std;
#define NAME "covering."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");

typedef tuple<int, bool, int> tibi;

int n, a, b;
int ans = 0;
void covering(vector<tibi> &x)
{
    vector<bool> flg(n, 0);
    vector<int> v(n);
    int pos_v = 0;
    //
    sort(x.begin(), x.end());
    for (int i = 0; i < 2 * n; i++)
    {
        auto [c, t, si] = x[i];
        if (t == 0)
            v[pos_v++] = si;
        else
        {
            if (flg[si] == 0)
            {
                for (int j = 0; j < pos_v; ++j)
                    flg[v[j]] = true;
                ++ans;
                pos_v = 0;
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
