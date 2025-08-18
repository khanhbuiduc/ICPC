#include <bits/stdc++.h>

using namespace std;
#define NAME "5G."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");

typedef tuple<int, bool, int> tibi;
//(coordinate(x/y), type(start/end), index(segment))

int n, a, b;
int m = 0; // xem đã đến cuối đoạn chưa
int k = 0;
void covering(vector<tibi> &x, vector<int> &ans)
{
    int c, t, si;
    for (int i = 0; i < 2 * n; i++)
    {
        tie(c, t, si) = x[i]; // (coordinate, type,segment index)
        if (m == 0)
        {
            ans.push_back(c);
            k++;
        }
        t == 0 ? m++ : m--;
        if (m == 0)
            ans.push_back(c);
    }
}
int main()
{
    fi >> n;
    vector<tibi> x(2 * n);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        fi >> a >> b;
        x[2 * i] = {a, 0, i};
        x[2 * i + 1] = {b, 1, i};
    }
    sort(x.begin(), x.end());
    covering(x, ans);
    fo << k << "\n";
    for (int i = 0; i < ans.size(); i++)
    {

        if (i % 2 == 1)
        {
            fo << ans[i] << "\n";
        }
        else
        {
            fo << ans[i] << " ";
        }
    }
    return 0;
}