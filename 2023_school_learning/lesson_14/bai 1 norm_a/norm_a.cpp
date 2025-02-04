#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    freopen("norm_a.inp", "r", stdin);
    freopen("norm_a.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> r(n);
    auto norm = [&]()
    {
        vector<pii> b(n);
        // tạo mảng B và bản sao của r=a
        for (int i = 0; i < n; i++)
        {
            b[i] = {a[i], i};
            r[i] = a[i];
        }
        // xắp xếp b theo thứu tự tăng dần
        sort(begin(b), end(b));
        // xắp xếp r theo thứ tự tăng dần và lọc các phần tử giống nhau
        sort(begin(r), end(r));
        auto t = unique(begin(r), end(r));
        int q;
        r.resize(t - r.begin());
        q = r.size();

        int p = 0;
        // với mỗi ri tìm các phần tử có b[p].first=ri
        for (int i = 0; i < q, p < n; i++)
            while (b[p].first == r[i])
                b[p++].first = i + 1;
        // ghi nhận a[b[p].second]=ri
        for (int i = 0; i < n; i++)
            a[b[i].second] = b[i].first;
    };
    norm();
    for (auto i : a)
        cout << i << " ";
}