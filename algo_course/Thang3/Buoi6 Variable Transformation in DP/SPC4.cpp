#include <bits/stdc++.h>
using namespace std;
int f[105][10'005];
int b[105], d[105];
const int INF = 10'001;
int n;

void minTime(int &a, int b)
{
    a = min(a, b);
}

int main()
{
    int T;
    cin >> T;
    for (int step = 1; step <= T; step++)
    {
        cin >> n;
        int sumB = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            sumB += b[i];
        }
        for (int i = 1; i <= n; i++)
            cin >> d[i];

        for (int i = 0; i <= n; i++)
            for (int t = 0; t <= sumB; t++)
                f[i][t] = INF;
        f[0][0] = 0;

        for (int i = 0; i <= n; i++)
            for (int t = 0; t <= sumB; t++)
            {
                if (f[i][t] == INF)
                    continue;
                minTime(f[i + 1][t + b[i + 1]], f[i][t]);
                minTime(f[i + 1][t], f[i][t] + d[i + 1]);
            }

        int res = INF;
        for (int t = 0; t <= sumB; t++)
            if (f[n][t] != INF)
                minTime(res, max(t, f[n][t])); // khi làm sai chỗ này

        cout << res << endl;
    }
    return 0;
}
/*
bún: 5 2 5 4 1 3 6 2
đậu: 9 1 5 2 4 10 4 2

--------------------------
1 <= N <= 100
1 <= b[i], d[i] <= 100
nếu 1 người cắt tóc cho n người thì thời gian tốn: 10^4

gọi f[i][t] là thời gian Đậu phục vụ ít nhất.
    khi thời gian bún phục vụ là t
    i vị khách ban đầu
BTCS:
    f[0][0] = b[1] +...b[n]
    f[i][t] = inf
kết quả: min( max(f[n][t], t)) với t: 0->10^4
QHD:
    khi f[i][t] != inf
    nếu vị khách thứ i + 1 bún phục vụ
        f[i+1][t + b[i+1]] = min(f[i+1][t + b[i+1]], f[i][t])
    nếu vị khách thứ i + 1 đậu phục vụ
        f[i+1][t] = min(f[i+1][t], f[i][t] + d[i])

*/