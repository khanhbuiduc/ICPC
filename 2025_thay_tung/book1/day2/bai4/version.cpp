#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, b, a) for (int i = (b); i >= (a); i--)
typedef long long ll;

ll one[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    int cnt = 0;
    FOR(i, 1, 17)
    one[i] = one[i - 1] * 10 + 1;

    FORD(i, 17, 1)
    {
        while (n >= one[i])
        {
            n -= one[i];
            cnt++;
        }
    }
    cout << cnt - 1;
}
