#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = a; i <= b; i++)
typedef pair<int, int> pii;
typedef long long ll;
int f[1005][1005];
int LCS(string s1, string s2)
{
    int len1 = s1.size();
    int len2 = s2.size();
    s1 = '0' + s1, s2 = '0' + s2; // base 1

    FOR(i, 0, len1)
    FOR(j, 0, len2)
    {
        if (s1[i + 1] == s2[j + 1])
            f[i + 1][j + 1] = f[i][j] + 1;
        else
        {
            f[i][j + 1] = max(f[i][j + 1], f[i][j]);
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
        }
    }
    return f[len1][len2];
}
int main()
{
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2))
    {
        cout << LCS(s1, s2) << endl;
    }
}
