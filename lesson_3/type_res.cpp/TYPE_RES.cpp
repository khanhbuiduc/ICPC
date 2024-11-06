#include <bits/stdc++.h>
using namespace std;
ifstream fi("input");
ofstream fo("output");
int main()
{
    string p = "NZQR";
    int t_div[4] = {2, 2, 2, 3};
    int t_minus[4] = {1, 1, 2, 3};
    char c1, c2, c3;
    int ans;
    fi >> c1 >> c2 >> c3;
    int t1 = p.find(c1);
    int t2 = p.find(c3);
    int tm = max(t1, t2);
    switch (c2)
    {
    case '+':
        ans = tm;
    case '-':
        ans = t_minus[tm];
    case '*':
        ans = tm;
    case '/':
        ans = t_div[tm];
    }
    cout << p[ans];
    fo << p[ans];
}