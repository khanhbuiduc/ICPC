#include <bits/stdc++.h>

using namespace std;
#define NAME "covering."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");

typedef tuple<int, bool, int> tibi;
//(coordinate(x/y), type(start/end), index(segment))
int c, t, si;

int n, a, b;
int pv = 0, ans = 0;
void covering(vector<tibi> &x)
{
    vector<bool> flg(n, 0);
    sort(x.begin(), x.end());
    vector<int> v(n); // active segments

    for (int i = 0; i < 2 * n; i++)
    {
        tie(c, t, si) = x[i]; // Unpack the tuple (coordinate, type, index)
        if (t == 0)           // Start of a segment
        {
            v[pv++] = si; // Add to active segments
        }
        else
        {
            if (flg[si] == 0) // If this segment is not covered yet
            {
                // Mark all active segments as covered
                for (int j = 0; j < pv; ++j)
                    flg[v[j]] = true;
                flg[si] = true; // Mark the current segment as covered
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