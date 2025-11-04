#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int a[200'005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    FOR(i, 1, n) { cin >> a[i]; }
    if (n == 1)
    {
        int m = min(a[1], k);
        ans = (a[1] + (a[1] - m + 1)) * m / 2;
        cout << ans;
        return 0;
    }
    else
    {
        int m1 = -1, m2 = -1;
        FOR(i, 1, n)
        {
            if (a[i] > m1)
            {
                m1 = a[i];
            }
            else if (a[i] > m2)
            {
                m2 = a[i];
            }
        }
        if (m1 == m2)
        {
            cout << m1 * k;
            return 0;
        }
        else
        {
            int m = (m1 - m2 + 1);
            int r = k % m;
            int ans1 = (m2 + m1) * m / 2;
            int ans2 = (m1 + (m1 - r + 1)) * r / 2;
            // cout << ans1 << ' ' << ans2 << endl;
            cout << (ans1 * (k / m) + ans2);
            return 0;
        }
        return 0;
    }
}
/*
ans = 0
cho a[1..n]: bài hát i có độ sảng khoái ai
    chọn bài hát i có ai lớn nhất.
        nếu có 2 bài cùng độ sảng khoái nghe bài mới hơn.
    nghe k lần.
    nghe 1 bài 2 lần sẽ giảm độ sảng khoái.
    nếu bằng 0 thì không giảm nữa
---
th1: n = 1:
    duyệt 1-> k
        ans += (ai--)
        nếu ai == 0 thì dừng.
    m = min(ai,k)
    ans = m*ai - (0+m-1)*m/2
---
th2: n!= 1
    tính max1, max2
    alice sẽ nghe:
        1 chu kì:
        m = max1 - max2 + 1
        ans1 = tổng(max1->max2) = (m2+m1)*m/2
        số chu kì: k/n
        chu kì cuối r =  k%n: ans2 = (m1 + m1-r+1) * r /2
        ans = ans1 * (n/k) +ans.


*/