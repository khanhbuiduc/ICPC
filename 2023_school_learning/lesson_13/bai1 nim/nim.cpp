#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("nim.inp", "r", stdin);
    freopen("nim.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    // tính s=a1^a2^...an
    int s = 0;
    for (int i : a)
        s ^= i;
    // nếu s=0 người thứ 1 không có cách nào thắng
    if (s == 0)
    {
        cout << "0";
        return 0;
    }
    // nếu s>0; tìm ai>=ai^s;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] ^ s) <= a[i])
        {
            res.push_back({i + 1, a[i] - (a[i] ^ s)});
        }
    }
    if (res.empty())
        cout << 0;
    else
    {
        cout << res.size() << "\n";
        for (auto [u, v] : res)
            cout << (u) << " " << v << "\n";
    }
}
