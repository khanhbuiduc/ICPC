#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
typedef long long ll;
typedef pair<int, int> pii;

int cnt[100'005], a[100'005];
int f[17][100'005];

void sieve()
{
    FOR(i, 1, 100'000)
    a[i] = i;

    FOR(i, 2, 100'000)
    {
        if (a[i] > 1)
        {
            for (int j = i; j <= 100'000; j += i)
            {
                while (a[j] % i == 0)
                {
                    cnt[j]++;
                    a[j] /= i;
                }
            }
        }
    }

    FOR(i, 1, 100'000)
    f[cnt[i]][i] = 1;

    FOR(k, 0, 16)
    FOR(j, 1, 100'000)
    f[k][j] += f[k][j - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int q, l, r, k;
    cin >> q;
    while (q--)
    {
        cin >> l >> r >> k;
        cout << f[k][r] - f[k][l - 1] << '\n';
    }
    return 0;
}
