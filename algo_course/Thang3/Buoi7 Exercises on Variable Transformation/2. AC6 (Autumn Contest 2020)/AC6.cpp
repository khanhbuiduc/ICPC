#include <bits/stdc++.h>
using namespace std;
const int INF = 2'000'007;
int f[100'005][51]; // là max viên loại 2 khi có i viên và j viên thứ 3
string store;
int t, n, m, k, d, g1, g2, g3;
void max_gach(int &a, int b)
{
    a = max(a, b);
}
int main()
{
    cin >> t;
    while (t--)
    {
        // n gạch, m lỗi, k loại 1, ô vỡ giảm độ đẹp d, ô lát độ đẹp g1,g2,g3
        cin >> n >> m >> k >> d >> g1 >> g2 >> g3 >> store;
        store = '0' + store; // chuyển base0->base1
        // btcs;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                f[i][j] = -1;

        f[0][0] = 0;
        // QHD:
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
            {
                if (f[i][j] == -1)
                    continue;
                // bỏ qua viên gạch thứ i+1;
                max_gach(f[i + 1][j], f[i][j]);
                // viên thứ viên thứ i+1, i+2 lát gạch 2
                if (i + 2 <= n && store[i + 1] == '.' && store[i + 2] == '.')
                    max_gach(f[i + 2][j], f[i][j] + 1);
                // viên gạch i+1,i+2,i+3 lát gạch 3
                if (i + 3 <= n && store[i + 1] == '.' && store[i + 2] == '#' && store[i + 3] == '.')
                    max_gach(f[i + 3][j + 1], f[i][j]);
            }
        int res = -99'999'999;
        for (int j = 0; j <= m; j++)
        {
            int so_loai_2_max = f[n][j];
            int so_loai_3 = j;
            for (int x = 0; x <= so_loai_2_max; x++) // chuyển x viên loại 2 thành 2x viên loại 1
            {
                int so_loai_2 = so_loai_2_max - x;
                int so_loai_1 = min(k, n - m - 2 * (so_loai_2)-2 * (so_loai_3));
                int val = so_loai_1 * g1 + so_loai_2 * g2 + so_loai_3 * g3 - d * (m - j);
                res = max(res, val);
            }
        }
        cout << res << endl;
    }
}
/*
Large Dataset: 0 ≤ M ≤ 50.
Trong mọi Dataset, ta có: 1 ≤ K ≤ N ≤ 100000, 0 ≤ D, G1, G2, G3 ≤ 100.


    => dùng đc tối đa M viên loại 3.
giả sử số viên loại 3 là j
    => f[j] là số viên gạch loại 2 tối đa
        khi có j viên gạch loại 3

những ô buộc phải lát viên loại 1:
    min(K , N - M - 2*(f[j]) - 2 * j)

giả sử thay x viên loại 2 thàng 2 * x viên loại 1
    số viên loại 1: v1= min(K, N - M - 2*(f[j]) - 2 * j + 2 * x);
    số viên loại 2: f[j] - x
    số viên loại 3: j

độ đẹp: v1 * g1 + v2 * g2 + v3 * g3 + (M - j) * D

--------------------------------
gọi f[i][j] là số viên loại 2 tối đa khi có i viên đầu tiên, và đã có j viên loại 3

btcs: f[0][0] = 0; f[i][j] = -1

QHD:
    nếu ô i+1 không nát gạch:
        f[i+1][j] = min(f[i+1][j], f[i][j]);
    nếu ô i+2<n: ô i+1 và i+2 là '.'
        f[i+2][j] = min(f[i+2][j], f[i][j] + 1)
    nếu i+3 <= N, ô i+1, i+3 là '.', ô i+2 là '#'
        f[i+3][j+1] = min(f[i+3][j+1], f[i][j]);
số viên gạch loại 2 tối đa khi có j viên gạch loại 3:
    f[N][j]
O(M*N);

*/