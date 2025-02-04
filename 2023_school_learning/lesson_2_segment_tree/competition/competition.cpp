#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second
void printArr(const vector<pii> &arr)
{
    for (const pii &i : arr)
        cout << "{" << i.ff << "," << i.ss << "} ";
    cout << "\n";
}
int main()
{
    freopen("competition.inp", "r", stdin);
    freopen("competition.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, r1 = 0, r2 = 0, t, k = 1, p, q;
    cin >> n >> m;

    // xây dựng cây phân đoạn lưu giá trị max max của đoạn đó
    //  khai báo
    while (k < n)
        k <<= 1;
    vector<pii> a(2 * k, {0, 0}), b(2 * k, {0, 0});
    // xây dựng nút lá cây phân đoạn
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[i + k] = {t, k + i};
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        b[k + i] = {t, i + k};
    }
    // xây dựng nút cha
    for (int i = k - 1; i > 0; --i)
    {
        (a[2 * i].ff > a[2 * i + 1].ff) ? a[i] = a[2 * i]
                                        : a[i] = a[2 * i + 1];

        (b[2 * i].ff > b[2 * i + 1].ff) ? b[i] = b[2 * i]
                                        : b[i] = b[2 * i + 1];
    }
    // tìm phần tử lớn nhất, và nhì trong đoạn u,v;
    auto get_max = [&](vector<pii> &z, int u, int v)
    {
        pii x, y;
        u += k - 1;
        v += k - 1;
        x = z[u];
        y = z[v];
        while (v - u > 1)
        {
            if (u % 2 == 0)
                x = max(x, z[u + 1]);
            if (v % 2 == 1)
                y = max(z[v - 1], y);
            u >>= 1;
            v >>= 1;
        }
        return max(x, y);
    };
    // t1,t2 là max a;
    // t3,t4 là max b;
    pii t1, t2, t3, t4;
    int kq1, kq2, ra, rb;
    for (int i = 0; i < m; i++)
    {
        // xet truy vấn p,q
        cin >> p >> q;
        // nếu 2 số liên tiếp thì kq1,kq2 bằng tổng 2 vị trí đó luôn
        if (q - p == 1)
        {
            kq1 = a[k + p - 1].ff + a[k + p].ff;
            kq2 = b[k + p - 1].ff + b[k + p].ff;
            if (kq1 > kq2)
                r1++; // a thắng r1 lần
            else if (kq1 < kq2)
                r2++; // b thắng r1 lần
            continue;
        }
        // mấy max nhất trong đoạn
        t1 = get_max(a, p, q);
        // tính max thứ 2;
        if (t1.ss == p - 1)
            t2 = get_max(a, p + 1, q);
        else if (t1.ss == q - 1)
            t2 = get_max(a, p, q - 1);
        else
        {
            t3 = get_max(a, p, t1.ss);
            t4 = get_max(a, t1.ss + 2, q);
            t2 = max(t3, t4);
        }
        ra = t1.ff + t2.ff;
        //=================================
        t1 = get_max(b, p, q);
        if (t1.ss == p - 1)
            t2 = get_max(b, p + 1, q);
        else if (t1.ss == q - 1)
            t2 = get_max(b, p, q - 1);
        else
        {
            t3 = get_max(b, p, t1.ss);
            t4 = get_max(b, t1.ss + 2, q);
            t2 = max(t3, t4);
        }
        rb = t1.ff + t2.ff;
        if (ra > rb)
            r1++;
        else if (ra < rb)
            r2++;
    }

    cout << r1 << ' ' << r2;
    cout << "\nTime: " << clock() / (double)1000 << " sec";
}