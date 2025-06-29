#include <bits/stdc++.h>
using namespace std;
bitset<1005> win[1005], lose[1005];
int main()
{
    int n;
    cin >> n;
    int aij;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> aij;
            if (aij == 1)
            {
                win[i].set(j);
                lose[j].set(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (win[i][j])
            {
                bitset<1005> temp = win[j] & lose[i];
                if (temp.count() == 0)
                    continue;
                for (int k = 1; k <= n; k++)
                {
                    if (temp[k])
                    {
                        cout << k << " " << i << " " << j;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1;
}
/*
i win j;
j win k;
k win i
=> khi i win j thì tìm k win i&& k lost j

*/