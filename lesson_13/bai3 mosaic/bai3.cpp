#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bai3.inp", "r", stdin);
    freopen("bai3.out", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
    if (m < n)
        swap(m, n);
    // số lượng lát cắt không vượt quá 3
    // nếu diện tích tấm đó bằng s thì không cần cắt
    if (s == m * n)
    {
        cout << "0";
        return 0;
    }
    // nếu s chia hết cho n hoặc m chỉ cần 1 lần cắt
    else if (s % n == 0 && s % m == 0)
    {
        cout << "1";
        return 0;
    }
    //
    else
    {
        // tính phần thừa còn lại của tấm
        int dentaS = m * n - s;
        for (int i = 1; i < n; i++)
        {
            // nếu viết được dưới dạng dantas=a*b với a<n và b<m
            // thì có thể cắt 2 lát
            if (dentaS % i == 0 && dentaS / i < m)
            {
                cout << "2";
                return 0;
            }
        }
    }
    cout
        << "3";
}