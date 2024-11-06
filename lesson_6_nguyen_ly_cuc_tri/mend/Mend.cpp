#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
ifstream fi("input");
ofstream fo("output");
int n, k;
#define ff first
#define ss second

int main()
{
    int m = 2520, p = 0, ans = 0;
    fi >> n >> k;

    vector<int64_t> s(n), a(n);
    vector<pii> sa(n); // Sắp xếp và tìm min(si)

    for (int i = 0; i < n; i++)
        fi >> s[i];

    for (int i = 0; i < n; i++)
        fi >> a[i];

    for (int i = 0; i < n; i++)
    {
        sa[i] = {s[i], a[i]};
        p += (int64_t)abs(s[i] - a[i]) * m / s[i]; // tổng độ lệch chuẩn
    }

    sort(sa.begin(), sa.end());

    for (int i = 0; i < n; i++)
    {
        s[i] = sa[i].ff;
        a[i] = sa[i].ss;
    }

    for (int i = 0; i < n; i++)
    {
        if (p <= k * m)
            break;
        if (p - abs(s[i] - a[i]) * m / s[i] > k * m)
        {
            ans += (int64_t)abs(s[i] - a[i]);
            p -= (int64_t)abs(s[i] - a[i]) * m / s[i];
        }
        else
        {
            ans += ((int64_t)(p - k * m) * s[i] + m - 1) / m;
            break;
        }
    }

    fo << ans;
}
