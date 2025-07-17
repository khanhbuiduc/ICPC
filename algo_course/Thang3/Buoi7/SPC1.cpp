#include <bits/stdc++.h>
using namespace std;
const int INF = 2'000'007;
int f[2005][2005];
int a[2005], b[2005];
int t, n, m;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        map<int, vector<int>> store;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            store[a[i]].push_back(i);
        }
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        // btcs
        for (int i = 0; i <= m; i++)
            for (int len = 0; len <= m; len++)
                f[i][len] = INF;
        f[0][0] = 0;
        // QHD
        for (int i = 0; i < m; i++)
            for (int len = 0; len <= i; len++)
            {
                if (f[i][len] == INF)
                    continue;
                // bỏ qua b[i+1]
                f[i + 1][len] = min(f[i + 1][len], f[i][len]);
                // xét b[i+1] vào dãy con chung
                int val = b[i + 1];
                if (store.find(val) != store.end())
                {
                    int ai = f[i][len];
                    auto p = upper_bound(store[val].begin(), store[val].end(), ai);
                    if (p != store[val].end())
                        f[i + 1][len + 1] = min(f[i + 1][len + 1], *p);
                }
            }
        int maxlength = 0;
        for (int len = 0; len <= m; len++)
        {
            if (f[m][len] <= n)
            {
                maxlength = len;
            }
        }
        cout << maxlength << endl;
    }
}

/*
Cho 2 day so a va b, day a gom N so nguyen duơng, day b gom M so nguyen dương.

Hãy tìm day c là day con chung co độ dai dai nhat của 2 day a va b

    f[i][j] là dộ dài lớn nhất của cả a và b. với i pt tử a, j phần tử của b.
    BTCS:
        f[i][0] = 0
        f[0][j] = 0
        f[i][j] = - inf
    kết quả: max(f[i][j]) với j: 0 -> m, i:0->n
    QHD: khi f[i][j] != - inf
        nếu a[i+1] = b[j+1]
            f[i+1][j+1] = max(f[i+1][j+1], f[i][j] + 1)
        không lấy a[i+1]
            f[i+1][j] = max(f[i+1][j], f[i][j])
        không lấy b[j+1]
            f[i][j+1] = max(f[i][j+1], f[i][j])
---------------------
Giới hạn dữ liệu: 1 <= N <= 2 triệu, 1 <= M <= 2000

maxleng chung của hãy a và b là 2000;

gọi f[i][len]: là vị trí tối thiểu của dãy a
    i phần tử dãy b
    độ dài con chung len
BTCS: f[0][0] = 0; f[i][len] = inf;

đáp án: max(len) khi f[M][len] < N;

QHD: khi f[i][len]!=inf
    xét b[i+1] không vào dãy con chung
        f[i+1][len] = max(f[i+1][len], f[i][len]);
    xét b[i+1] vào dãy con chung
        tìm vị trí p mà a[p] = b[i+1] mà p > f[i][len]
            f[i+1][len+1] = min(f[i+1][len+1], p)
----------
cách tìm p trong dãy a: khoảng [f[i][len], N]
ta lưu trữ trong 1 map<value, list<index>>:
    store: vị trí, giá trị.
    tìm upperbound từ vị trí đến vị trí. c
*/