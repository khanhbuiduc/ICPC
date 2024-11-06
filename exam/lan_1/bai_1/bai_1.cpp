#include <bits/stdc++.h>
using namespace std;
ifstream fi("input");
ofstream fo("output");
int main()
{
    string str = "";
    fi >> str;
    int count = 0;
    // so sánh chuỗi bên phải với chuỗi bên trái
    string l = "";
    string r = "";
    string ans = "";
    int li = 0, ri = str.size() - 1;

    while (li < ri)
    {
        l = l + str[li];
        r = str[ri] + r;
        if (l == r) // nếu bên phải bằng bên trái count++ và l,r về rỗng, lưu kết quả.
        {
            count++;
            ans = ans + l + "\n";
            l = "";
            r = "";
        }
        li++;
        ri--;
    }
    ans = to_string(count) + "\n" + ans;
    fo << ans;
}