#include <bits/stdc++.h>
using namespace std;
#define NAME "chase"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int64_t t, d = 0; // khoảng cách gia tăng do đổ dầu
double ans = 0;
int main()
{
    int n, k, v1, v2, s, a[100001], x[100001];
    fi >> n >> k >> v1 >> v2 >> s;
    for (int i = 0; i < n; i++)
        fi >> x[i] >> a[i];
    priority_queue<int> q;
    // xe bắt, xe chạy ở cùng chỗ
    if (s == 0)
    {
        fo << "0 ";
        return 0;
    };
    // xe bắt không bao h đuổi được xe chạy
    if (s > 0 && v1 >= v2)
    {
        fo << "inf";
        return 0;
    }
    // xe chạy trốn bắt đầu từ điểm s nên không thể đổ dầu trc s.
    int m = 0;
    for (int i = 0; i < n; i++)
        if (x[i] >= s)
        {
            m = i;
            break;
        };

    while (k > 0) // dừng khi hết thùng dầu
    {
        // xe trốn đến xi trước
        for (int i = m; i < n; i++)
        {
            if ((double)(x[i] - s) / v1 >= (double)(x[i] + d) / v2)
                break;

            m++;
            q.push(a[i]);
        }
        // xe đuổi đến xi trước
        k--;
        if (!q.empty())
            t = q.top();
        else
            break;
        d += t * v2;
        q.pop();
    }
    ans = (double)(s + d) / (v2 - v1);
    fo << fixed << setprecision(6) << ans;
}