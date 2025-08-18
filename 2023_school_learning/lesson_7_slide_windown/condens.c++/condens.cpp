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
    int n = s.size();
    //  Áp dụng định lý Lucas: C(n-1, i) mod 2 = 1 nếu (n-1) & i = i
    for (int i = 0; i < n; i++)
    {
        if (((n - 1) & i) == i) // kiểm tra chẵn lẻ của C(n-1, i)
            ans ^= (s[i] - '0');
    }
    cout << ans;
    return 0;
}