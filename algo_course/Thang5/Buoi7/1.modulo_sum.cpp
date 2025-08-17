#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAXN = 100'005;
int f[105][105][2];
vector<int> a;
int n, k;
ll fact[MAXN], inv_fact[MAXN];
void initial()
{
    cin >> n >> k;
    a.resize(n);
    for (int &i : a)
        cin >> i;
    f[0][0][0] = 1;
}
int main()
{
    initial();
    // nếu n>k luôn tìm đc cách
    if (n > k)
    {
        cout << "YES";
        return 0;
    }
    FOR(i, 0, n)
    FOR(r, 0, k - 1)
    FOR(state, 0, 1)
    {
        if (!f[i][r][state])
            continue;
        // số i+1 không được chọn.
        f[i + 1][r][state] = 1;
        // số i +1 được chọn
        int cur_r = (r + a[i + 1 - 1]) % k;
        f[i + 1][cur_r][1] = 1;
    }
    cout << (f[n][0][1] ? "YES" : "NO");
}