#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x0, y0, r, a, b, c, xA, yA, xB, yB;
    cin >> x0 >> y0 >> r >> a >> b >> c >> xA >> yA >> xB >> yB;
    int OA, OB;
    OA = (x0 - xA) * (x0 - xA) + (y0 - yA) * (y0 - yA);
    OB = (x0 - xB) * (x0 - xB) + (y0 - yB) * (y0 - yB);

    bool flg1 = OA == r * r, flg2 = OB == r * r;

    // Nếu cả hai điểm đều không nằm trên đường tròn
    if (!flg1 && !flg2)
    {
        cout << "YES";
        return 0;
    }

    // Nếu bán kính = 0 hoặc không có điểm nào trên đường tròn
    if (r == 0)
    {
        if ((a * (xB - xA) + b * (yB - yA)) == 0)
            cout << "YES";
        else
            cout << "NO";
        return 0;
    }

    // Nếu điểm thứ 2 nằm trên đường tròn, swap để điểm thứ 1 nằm trên đường tròn
    if (flg2)
    {
        swap(xA, xB);
        swap(yA, yB);
    }

    // Tính khoảng cách từ tâm đường tròn đến đường thẳng qua xB với vector pháp tuyến (a,b)
    int tuso, mauso;
    tuso = a * x0 + b * y0 + c - (a * xB + b * yB + c);
    mauso = a * a + b * b;

    if (tuso * tuso <= mauso * r * r)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}