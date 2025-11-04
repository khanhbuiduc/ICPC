#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long ones[20] = {0, 1};
    for (int i = 2; i < 20; ++i)
        ones[i] = ones[i - 1] * 10 + 1; // tạo ra 1, 11, 111, 1111, ...

    long long a;
    cin >> a;

    int res = 0;
    while (a > 0)
    {
        // Tìm số repdigit lớn nhất <= a và trừ đi
        for (int i = 18; i >= 1; --i)
        {
            if (ones[i] <= a)
            {
                a -= ones[i];
                res++;
                break;
            }
        }
    }

    cout << res;
    return 0;
}