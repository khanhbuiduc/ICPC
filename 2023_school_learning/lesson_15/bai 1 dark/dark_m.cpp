#include <bits/stdc++.h>
using namespace std;
// 0A lùi đầu dòng, 13H là xuống dòng
//__int128: 10^39; int64=10^
int main()
{
    freopen("dark_m.inp", "r", stdin);
    freopen("dark_m.out", "w", stdout);
    int n;
    string s;
    __int128_t num;
    __int128_t sum = 0;
    cin >> n;
    // convert string to num
    auto get_n = [&]()
    {
        num = 0;
        int flg = 0;
        if (s[0] == '-')
        {
            flg = 1;
            s.erase(0, 1);
        }
        while (s != "")
        {
            num = num * 10 + s[0] - '0';
            s.erase(0, 1);
        }
        return flg ? -num : num;
    };
    // convert num to string
    auto pts = [&]()
    {
        s = "";
        int flg = 0;
        if (sum < 0)
        {
            flg = 1;
            sum = -sum;
        }
        while (sum > 0)
        {
            s = (char)(sum % 10 + '0') + s;
            sum /= 10;
        }

        return flg ? '-' + s : s;
    };
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        sum += get_n();
    }
    sum /= n;
    cout << pts();
}