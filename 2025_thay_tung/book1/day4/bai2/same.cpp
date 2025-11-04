#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;

// Hàm tính bình phương khoảng cách giữa 2 điểm
int cac(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int x1, y1, x2, y2, x3, y3;
    int x4, y4, x5, y5, x6, y6;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cin >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    int a = cac(x1, y1, x2, y2);
    int b = cac(x2, y2, x3, y3);
    int c = cac(x3, y3, x1, y1);

    // Tính 3 cạnh của tam giác 2
    int d = cac(x4, y4, x5, y5);
    int e = cac(x5, y5, x6, y6);
    int f = cac(x6, y6, x4, y4);

    vector<int> tam_giac = {a, b, c, a, b, c};
    // Kiểm tra 2 tam giác có bằng nhau không
    FOR(i, 0, 2)
    {
        if (tam_giac[i] == d && tam_giac[i + 1] == e && tam_giac[i + 2] == f)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}

/*
cho
tam giác 1: A(x1,y1) B(x2,y2) C(x3,y3)
tam giác 2: F(x4,y4) D(x5,y5) E(x6,y6)
hỏi 2 tam giác có bằng nhau nếu tịnh tiến và xoay (không lật).
---
Ý tưởng:
- Tính độ dài 3 cạnh của mỗi tam giác (dùng bình phương khoảng cách để tránh sai số)
-  nếu 3 cạnh theo bằng nhau nếu xét lần lượt cạnh theo thứ tự nào đó.
    a == d && b = e && c == f
    b ==d && c == e && a == f
    c == d && a ==e && b == f
*/