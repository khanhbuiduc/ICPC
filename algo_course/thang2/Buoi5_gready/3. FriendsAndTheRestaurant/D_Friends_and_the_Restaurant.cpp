#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int n;
int x[100'005], y[100'005], b[100'005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        for (int i = 1; i <= n; i++)
            cin >> y[i];
        for (int i = 1; i <= n; i++)
            b[i] = y[i] - x[i];
        sort(b + 1, b + n + 1);
        int l = 1, r = n, group = 0;
        while (l < r)
        {
            if (b[r] + b[l] >= 0)
            {
                group++;
                l++;
                r--;
            }
            else
                l++;
        }
        cout << group << "\n";
    }
}
