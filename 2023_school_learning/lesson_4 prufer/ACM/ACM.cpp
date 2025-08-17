#include <bits/stdc++.h>
using namespace std;
ifstream fi("ACM.INP");
ofstream fo("ACM.OUT");
int main()
{
    int m, n;
    fi >> m >> n;
    vector<string> carpet(m + 2);
    string barrier(n + 2, 0);
    carpet[0] = barrier;
    carpet[m + 1] = barrier;
    for (int i = 1; i <= m; i++)
    {
        string mi;
        fi >> mi;
        carpet[i] = "0" + mi + "0";
    }
    ////////////////////////////////////
    int ac;
    int mc;
    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (carpet[i][j] == 'C')
            {
                ac = 0;
                mc = 0;
                if (carpet[i][j - 1] == 'A')
                {
                    ac++;
                }
                else if (carpet[i][j - 1] == 'M')
                {
                    mc++;
                }
                if (carpet[i][j + 1] == 'A')
                {
                    ac++;
                }
                else if (carpet[i][j + 1] == 'M')
                {
                    mc++;
                }
                if (carpet[i + 1][j] == 'A')
                {
                    ac++;
                }
                else if (carpet[i + 1][j] == 'M')
                {
                    mc++;
                }
                if (carpet[i - 1][j] == 'A')
                {
                    ac++;
                }
                else if (carpet[i - 1][j] == 'M')
                {
                    mc++;
                }
                count += ac * mc;
            }
        }
    }
    cout << count;
    fo << count;
}