#include <bits/stdc++.h>
using namespace std;
// 0A lùi đầu dòng, 13H là xuống dòng
//__int128: 10^39; int64=10^
int main()
{
    freopen("compressed.inp", "r", stdin);
    freopen("compressed.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    auto get = [&]()
    {
        // tạo mản trung gian B, copy A
        vector<pair<int, int>> B(n);
        vector<int> r(n);
        for (int i = 0; i < n; i++)
        {
            B[i] = {a[i], i};
            r[i] = a[i];
        }
        // ss theo thứ tự tăng dần
        sort(begin(B), end(B));
        sort(begin(r), end(r));
        // lọc các phần tử giống nhau
        r.resize(unique(begin(r), end(r)) - r.begin());
        // thay thế các phần tử của A bằng số thứ tự của các đại diện tương ứng trong B
        int p = 0;
        for (int i = 0; i < r.size(), p < n; i++)
            while (B[p].first == r[i])
                B[p++].first = i + 1;
        for (int i = 0; i < n; i++)
            a[B[i].second] = B[i].first;
    };
    get();
    for (auto i : a)
        cout << i << " ";
}