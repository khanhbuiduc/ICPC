#include <bits/stdc++.h>

using namespace std;
ifstream fi("input");
ofstream fo("output");
int main()
{
    int n, k, p, q;
    fi >> n >> k >> p >> q;
    n = n % 2 == 1 ? ++n : n;
    int alice = 2 * (p - 1) + q;
    int bob = (alice - k > 0) ? alice - k : alice + k;
    if (bob > n)
    {
        fo << -1;
        return 0;
    }
    int row = (bob + 1) / 2;
    int col = bob % 2 == 0 ? 2 : 1;
    fo << row << " " << col;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     freopen("input", "r", stdin);
//     freopen("output", "w", stdout);
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n, k, p, q, u, v;
//     cin >> n >> k >> p >> q;

//     int x = (p - 1) * 2 + q;    // Tính vị trí của Alice
//     int x1 = x - k, x2 = x + k; // Vị trí Bob có thể ngồi cách Alice k vị trí
//     int u1 = 0, v1 = 0, u2 = 0, v2 = 0;

//     // Tính hàng và cột cho vị trí x1
//     if (x1 > 0)
//     {
//         u1 = (x1 + 1) / 2;
//         v1 = x1 - (u1 - 1) * 2;
//     }

//     // Tính hàng và cột cho vị trí x2
//     if (x2 <= n)
//     {
//         u2 = (x2 + 1) / 2;
//         v2 = x2 - (u2 - 1) * 2;
//     }

//     u = -n; // Đặt giá trị ban đầu cho u (giá trị không hợp lệ)

//     // Lựa chọn vị trí hợp lý cho Bob
//     if (u1 > 0)
//     {
//         u = u1;
//         v = v1;
//     }
//     if (u2 > 0 && u2 - p < p - u)
//     {
//         u = u2;
//         v = v2;
//     }

//     // In kết quả
//     if (u > 0)
//     {
//         cout << u << " " << v;
//     }
//     else
//     {
//         cout << -1;
//     }

//     return 0;
// }
