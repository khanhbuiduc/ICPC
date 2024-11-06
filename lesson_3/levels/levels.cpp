#include <bits/stdc++.h>
using namespace std;
ifstream fi("LEVELS.INP");
ofstream fo("LEVELS.OUT");
int main()
{
    int v;
    string s;
    fi >> v >> s;
    int curlevel;
    string ans = "";
    if (v < 1601)
    {
        curlevel = 3;
    }
    else if (v < 1901)
    {
        curlevel = 2;
    }
    else
    {
        curlevel = 1;
    }
    for (char c : s)
    {
        if (curlevel >= c - '0')
        {
            ans += string(1, c) + "\n";
        }
        else
        {

            ans += string(1, c) + "*\n";
        }
    }
    fo << ans;
}