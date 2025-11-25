#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> a;
ll need;

// Kiểm tra xem có đoạn dài len thỏa sum - min >= need không
bool ok(int len)
{
    if (len < 2)
        return false;
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + a[i - 1];

    for (int i = 0; i + len <= n; i++)
    {
        ll sum = prefix[i + len] - prefix[i];
        ll mn = *min_element(a.begin() + i, a.begin() + i + len);
        if (sum - mn >= need)
            return true;
    }
    return false;
}

void bs()
{
    int l = 2, r = n, ans = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(mid))
        {
            ans = mid - 1;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;
    a.resize(n);
    ll total = 0;
    for (ll &x : a)
    {
        cin >> x;
        total += x;
    }

    need = (total + 1) / 2;
    bs();
    return 0;
}

/*
n = 4
1,2,3,4

need = (sum[1..n] + 1) /2;
sum[l..r] - min[l..r] >= need
---
need = 5
min1 = 1,min2=-1, sum = 1 < need
[1]
---
min1 = 1,min2=2, sum = 3<need
[1,2]
---
min1 = 1,min2=2, sum = 6 - 1 >= need
[1,2,3]
====>update ans.
---
...

*/