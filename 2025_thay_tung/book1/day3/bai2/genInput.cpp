#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0)); // Khởi tạo random seed

    int n = 100'000;
    int MaxVal = 1'000'000'000;
    // Tạo file output
    freopen("input.txt", "w", stdout);

    // In n
    cout << n << '\n';

    // In n số ngẫu nhiên từ 1 đến 10^9
    for (int i = 1; i <= n; i++)
    {
        long long num = (1LL * rand() * rand()) % MaxVal + 1;
        cout << num;
        if (i < n)
            cout << ' ';
    }
    cout << '\n';

    // In n số ngẫu nhiên từ 1 đến 10^9 (dòng thứ 2)
    for (int i = 1; i <= n; i++)
    {
        long long num = (1LL * rand() * rand()) % MaxVal + 1;
        cout << num;
        if (i < n)
            cout << ' ';
    }
    cout << '\n';

    cerr << "Da tao file input.txt thanh cong!\n";

    return 0;
}