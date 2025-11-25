#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
const int M = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k, p;
    cin >> n;
    k = n >> 1;
    vector<int> a(n);
    vector<pii> tr(4 * k, {M, 0});

    for (int &i : a)
        cin >> i;
    sort(a.begin(), a.end());

    p = 1;
    while (p < k)
        p <<= 1;

    // Khởi tạo segment tree - LỖI: a[i] thay vì a[i-1]
    for (int i = 1; i <= k; ++i)
    {
        tr[p + i - 1] = {a[i - 1] + a[n - i], a[i - 1] + a[n - i]};
    }

    // Build segment tree
    for (int i = p - 1; i > 0; --i)
    {
        tr[i].ff = min(tr[2 * i].ff, tr[2 * i + 1].ff);
        tr[i].ss = max(tr[2 * i].ss, tr[2 * i + 1].ss);
    }

    int res = tr[1].ss - tr[1].ff;

    auto upd_res = [&](int j)
    {
        int idx = p + j;
        while (idx > 0)
        {
            idx >>= 1;
            tr[idx].ff = min(tr[2 * idx].ff, tr[2 * idx + 1].ff);
            tr[idx].ss = max(tr[2 * idx].ss, tr[2 * idx + 1].ss);
        }
        // THÊM DÒNG NÀY: cập nhật kết quả
        res = min(res, tr[1].ss - tr[1].ff);
    };

    for (int i = 0; i < k; ++i)
    {
        tr[p + i] = {a[i] + a[n - i - 1], a[i] + a[n - i - 1]};
        upd_res(i);
    }

    int p1 = p + k;
    for (int i = 1; i <= k; ++i)
    {
        tr[p1 - i] = {a[k - i] + a[k + i - 1], a[k - i] + a[k + i - 1]};
        upd_res(k - i);
    }

    cout << res;

    return 0;
}