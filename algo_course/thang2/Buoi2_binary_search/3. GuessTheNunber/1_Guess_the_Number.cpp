#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;

int main()
{
    // freopen("input.txt", "r", stdin),
    // freopen("output.txt", "w", stdout);
    int l = 1, r = 1000000;
    int mid, res = 0;
    string ans;

    while (l <= r)
    {
        mid = (l + r) / 2;
        cout << mid << "\n";
        fflush(stdout);
        cin >> ans;
        if (ans == ">=")
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << "! " << res << "\n";
    fflush(stdout);
    return 0;
}
// 12