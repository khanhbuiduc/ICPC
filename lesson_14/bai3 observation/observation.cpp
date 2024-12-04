#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
int main()
{
    freopen("observation.inp", "r", stdin);
    freopen("observation.out", "w", stdout);
    int w, h, k; // hàng, cột, đèn
    cin >> w >> h >> k;
    vector<int> x(k), y(k); // lưu hàng và cột có camera
    // Việc di chuyển camera theo hàng độc lập với theo cột
    for (int i = 0; i < k; i++)
        cin >> x[i] >> y[i];

    auto get = [&](vector<int> x, int w)
    {
        sort(all(x));
        auto t = unique(all(x)); //{1,2,1}=>{1,2,?} trả về vị trí sau pt 2;
        x.resize(t - x.begin());
        int n = x.size();

        int longest = (w - (x.back() - x[0] + 1)) % w;
        int mshift = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // Xét 2 cột ci và ci+1 có chứa camera
            if (x[i + 1] - x[i] - 1 >= longest)
            {
                // sô phép cần sử lý: ci sang trái hoặc w-c(i+1)+1 sang phải
                int sht = min(x[i], w - x[i + 1] + 1);
                if (x[i + 1] - x[i] - 1 == longest)
                    mshift = min(mshift, sht);
                else
                    mshift = sht; // nếu không thực hiện phép dịch: cn-ci+1
                // tìm khoảng cột chống lớn và với số phép biến đổi ít nhất giữa các cặp cột đã cho theo trình tự tăng dần
                longest = x[i + 1] - x[i] - 1;
            }
        }
        return make_pair(w - longest, mshift);
    };

    pii g1 = get(x, w);
    pii g2 = get(y, h);
    cout << (ll)g1.first * g2.first << " " << g1.second + g2.second << "\n";
}

// Cần tìm khoảng các cột trống lớn nhất và dồn những cột này sang bên trái hoặc phải của trường đã cho
// cần tìm khoảng cách hàng chống lớn nhất và dồn những hàng này lên trên hoặc xuống dưới trường đã cho