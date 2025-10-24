#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int l = 0;
        int countZero = 0, ans = 0;
        for (int r = 0; r < n; r++)
        {
            if (a[r] == 0)
                countZero++;
            while (l < r && countZero > k)
            {
                if (a[l] == 0)
                    countZero--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << "\n";
    }
}