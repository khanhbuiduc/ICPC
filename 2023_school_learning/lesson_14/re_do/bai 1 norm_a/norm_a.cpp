#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define all(a) begin(a), end(a)
int main()
{
    freopen("norm_a.inp", "r", stdin);
    freopen("norm_a.out", "w", stdout);
    // store: A:vector
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    auto norm = [&]()
    {
        // SET<piI> b lưu value và index của từng phần tử trong a
        // r: là bản sao của A
        vector<pii> B;
        vector<int> r(n);
        for (int i = 0; i < n; i++)
        {
            B.push_back({a[i], i});
            r[i] = a[i];
        }
        // lọc r và sort chỉ để lại những số không trùng;
        sort(all(r));
        sort(all(B));
        r.resize(unique(all(r)) - begin(r));
        // tìm những phần tử của B= ri và thay đổi value đó thành i+1;
        int p = 0;
        for (int i = 0; i < r.size(), p < n; i++)
            while (B[p].first == r[i])
            {
                B[p++].first = i + 1;
            }
        // duyệt B thay đổi A dựa vào vị trí và giá trị của mỗi phần tử của B
        for (auto [k, v] : B)
            a[v] = k;
    };
    norm();
    for (int i : a)
        cout << i << " ";
}