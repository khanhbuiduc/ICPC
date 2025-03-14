#include <bits/stdc++.h>

using namespace std;
#define NAME "condens."
// ifstream fi(NAME "inp");
// ofstream fo(NAME "out");

int main()
{
    string s;
    // fi >> s;
    cin >> s;
    int ans = 0;
    int n = s.size() - 1;
    for (int i = 0; i < n; i++)
    {

        if (i & ~n)
            continue;
        ans ^= ((s[i] - '0'));
    }
    cout << ans;
}