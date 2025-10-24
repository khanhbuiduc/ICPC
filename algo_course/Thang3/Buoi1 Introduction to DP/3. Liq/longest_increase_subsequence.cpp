#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int a[1005];
int f[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
    }
    int maxLeng = 0;
    for (auto fi : f)
        maxLeng = max(maxLeng, fi);
    cout << maxLeng;
}