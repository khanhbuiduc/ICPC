#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int curi = 1;
    // vị trí hiện tại > t thì dừng
    while (curi <= t)
    {
        // nếu vị trí hiện tại bằng t dừng
        if (curi == t)
        {
            cout << "YES";
            return 0;
        }
        // nếu không nhảy đến cổng kết nối
        curi += a[curi];
    }
    cout << "NO";
    return 0;
}