#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int f[1005][1005];
int main()
{
    string s1, s2;
    while (getline(std::cin, s1) && getline(std::cin, s2))
    {

        int m = s1.size();
        int n = s2.size();
        for (int i = 0; i <= m; i++)
            f[i][0] = 0;
        for (int j = 0; j <= n; j++)
            f[0][j] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }
        cout << f[m][n] << endl;
    }
}
