#include <bits/stdc++.h>
using namespace std;
// 0A lùi đầu dòng, 13H là xuống dòng
//__int128: 10^39; int64=10^
int main()
{
    freopen("compressed.inp", "r", stdin);
    freopen("compressed.out", "w", stdout);
    int n, p;
    cin >> n;
    vector<int> a(n), b;
    set<int> s;
    for (int &i : a)
        cin >> i;
    // nạp các phần tử A vào tập S
    for (int i : a)
        s.insert(i);
    // nạp các phần tử s vào vector B
    for (int i : s)
        b.push_back(i);
    // Thay các phần tử của A bằng số thứ tự đại diện tương ứng trong B

    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        // tìm vị trí phần tử a[i] trong b; vs log(n)
        p = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        c[i] = p + 1;
    }
    for (int i : c)
        cout << i << ' ';
    cout << '\n';
}