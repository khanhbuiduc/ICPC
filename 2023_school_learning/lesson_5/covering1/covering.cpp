
#include <bits/stdc++.h>

using namespace std;
#define NAME "covering."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
int n, ans = 1;
typedef pair<int, int> pii;
int main()
{
    fi >> n;
    vector<pii> a(n);
    for (auto &i : a)
        fi >> i.first >> i.second;

    sort(a.begin(), a.end());
    pii seg = a[0];
    for (int i = 1; i < n; i++)
    {
        pii cur = a[i];
        if (cur.first <= seg.second)
        {
            seg.first = cur.first;
            if (cur.second < seg.second)
            {
                seg.second = cur.second;
            }
        }
        else
        {
            ans++;
            seg = cur;
        }
    }
    fo << ans;
}