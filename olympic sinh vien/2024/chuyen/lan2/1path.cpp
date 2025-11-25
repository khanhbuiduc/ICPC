#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;

int n, m, numBlock;
const int MAXN = 200'005;
const int maxBlock = 2;
bool isBlock[1005][1005];
ll a[1005][1005];
ll fact[MAXN], inv_fact[MAXN];
int MOD = 1'000'000'007;

ll powMod(ll a, ll b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

void pre_calculator()
{
    fact[0] = 1;
    FOR(i, 1, MAXN - 1)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[MAXN - 1] = powMod(fact[MAXN - 1], MOD - 2);
    FORD(i, MAXN - 2, 0)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

ll C(ll n, ll k)
{
    if (k > n || k < 0 || n >= MAXN)
        return 0;
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n - k]) % MOD;
}

void initial()
{
    cin >> n >> m >> numBlock;
    FOR(i, 1, numBlock)
    {
        int x, y;
        cin >> x >> y;
        isBlock[x][y] = true;
    }
    pre_calculator();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    initial();
    a[1][1] = 1;

    FOR(i, 1, min(maxBlock, n))
    FOR(j, 1, min(maxBlock, m))
    {
        if (!isBlock[i + 1][j])
            (a[i + 1][j] += a[i][j]) %= MOD;
        if (!isBlock[i][j + 1])
            (a[i][j + 1] += a[i][j]) %= MOD;
    }

    if (n <= maxBlock && m <= maxBlock)
    {
        cout << a[n][m];
        return 0;
    }

    ll ans = 0;

    if (n > maxBlock)
    {
        FOR(col, 1, min(m, maxBlock))
        {
            int down = n - maxBlock; // số ô: maxBlock + 1 -> n
            int right = m - col + 1; // số ô: col -> n
            (ans += (a[maxBlock][col] * C(down + right - 2, down - 1) % MOD)) %= MOD;
        }
    }

    if (m > maxBlock)
    {
        FOR(row, 1, min(n, maxBlock))
        {
            int right = m - maxBlock;
            int down = n - row + 1;
            (ans += (a[row][maxBlock] * C(right + down - 2, right - 1) % MOD)) %= MOD;
        }
    }

    cout << ans;
    return 0;
}