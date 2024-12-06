#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("keyboard.inp", "r", stdin);
    freopen("keyboard.out", "w", stdout);
    string s;
    cin >> s;
    int n, ans = s.size();
    cin >> n;
    while (n--)
    {
        char c;
        int x;
        cin >> c >> x;
        int noc = count(s.begin(), s.end(), c);
        ans += ((noc + (x - 2)) / (x - 1));
    }
    cout << ans;
}