#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t ans = 0;
    int n;
    cin >> n;
    n--;
    for (int i = 0; i <= n; i++)
    {
        int64_t x;
        cin >> x;
        if ((i & n) == i)
            ans ^= (x);
    }
    cout << ans;
}
