#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
pii a[55];
int countCandy[55];
int n, k;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        memset(countCandy, 0, sizeof(countCandy));
        for (int i = 1; i <= n; i++)
            cin >> a[i].ss >> a[i].ff;
        if (k == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        sort(a + 1, a + n + 1, greater<pii>());
        int ans = 0;
        int sumCandy = 0;
        for (int i = 1; i <= n; i++)
        {

            if (countCandy[a[i].ss] >= k)
                continue;
            ans += a[i].ff;
            sumCandy++;
            countCandy[a[i].ss]++;
            if (sumCandy == 2 * k)
            {
                cout << ans << "\n";
                break;
            }
        }
        if (sumCandy < 2 * k)
            cout << -1 << "\n";
    }
}