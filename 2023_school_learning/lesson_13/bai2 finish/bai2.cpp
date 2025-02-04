#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    int a, b, m, t;
    string s = "";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> m;
        // các điểm có tọa độ b-i(m+1) là nhân thắng của trò chơi
        //(b-a) không chia hết cho m+1 thì người thứ 1 thắng nếu không người thứ 2 thắng
        (b - a) % (m + 1) ? cout << "R" : cout << "B";
    }
}