#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    // f[i][s][cnt] tách thành
    //  p[i][r] = giá trị cuối để đạt được tổng r với i phần tử
    //  lv[i][m] = tổng thứ m có thể đạt được với i phần tử
    //  cnt[i] = số lượng tổng khác nhau có thể đạt được với i phần tử
    vector<vector<int>> trace(k + 1, vector<int>(n + 1, 0));
    vector<vector<int>> lv(k + 1, vector<int>(n + 1, 0));
    vector<int> cnt(k + 1, 0);

    // Base case: với 0 phần tử, chỉ có thể đạt tổng 0
    cnt[0] = 1;
    lv[0][0] = 0;

    // Duyệt qua tất cả các giá trị có thể: n - i²
    for (int i = 1; i * i < n; ++i)
    {
        int v = n - i * i;

        // Duyệt ngược từ k-1 về 0 để tránh sử dụng cùng một giá trị nhiều lần
        for (int q = k - 1; q >= 0; --q)
        {
            // Duyệt qua tất cả các tổng có thể đạt được với q phần tử
            for (int m = 0; m < cnt[q]; ++m)
            {
                int j = lv[q][m]; // Tổng hiện tại với q phần tử

                // Nếu thêm v vào không vượt quá n và chưa được tính
                if (j + v <= n && trace[q + 1][j + v] == 0)
                {
                    trace[q + 1][j + v] = v;       // Lưu giá trị được thêm vào
                    lv[q + 1][cnt[q + 1]] = j + v; // Lưu tổng mới
                    cnt[q + 1]++;                  // Tăng số lượng tổng có thể đạt được
                }
            }
        }
    }

    // Kiểm tra xem có thể đạt tổng n với k phần tử không
    if (trace[k][n] != 0)
    {
        cout << "YES\n";
        int r = n;
        // Truy vết ngược để tìm các phần tử
        for (int q = k; q > 0; --q)
        {
            cout << trace[q][r] << " ";
            r -= trace[q][r];
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}