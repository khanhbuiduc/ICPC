#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const int M = 1e5;
    vector<int> b(M + 1), p(M + 1, 0);
    vector<vector<int>> f(17, vector<int>(M + 1, 0));

    // Khởi tạo
    for (int i = 0; i <= M; ++i)
        b[i] = i;

    // Đếm số lượng ước nguyên tố phân biệt của mỗi số
    for (int i = 2; i <= M; ++i)
    {
        if (b[i] > 1)
        {
            for (int j = b[i]; j <= M; j += b[i])
            {
                while (b[j] % b[i] == 0)
                {
                    p[j]++;
                    b[j] /= b[i];
                }
            }
        }
    }

    // f[k][i] = số lượng số ≤ i có đúng k ước nguyên tố phân biệt
    for (int i = 1; i <= M; ++i)
        if (p[i] <= 16)
            f[p[i]][i] = 1;

    for (int k = 0; k <= 16; ++k)
        for (int i = 1; i <= M; ++i)
            f[k][i] += f[k][i - 1];

    int q;
    cin >> q;
    while (q--)
    {
        int lf, rt, k;
        cin >> lf >> rt >> k;
        cout << f[k][rt] - f[k][lf - 1] << '\n';
    }

    return 0;
}
