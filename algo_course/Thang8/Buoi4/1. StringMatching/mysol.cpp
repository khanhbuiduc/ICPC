#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
ll hashT = 0;
ll prefix[1'000'005];
ll power31[1'000'005];
string s, t;
int n, m;
void initial()
{
    cin >> s >> t;
    n = s.length(), m = t.length();
    // tính power31
    power31[0] = 1;
    FOR(i, 1, 1'000'000) { power31[i] = power31[i - 1] * 27; }
    // tính hashT
    FOR(i, 1, m) { hashT += (t[i - 1] - 'a' + 1) * power31[i - 1]; }
    // tính prefix của s
    prefix[0] = 0;
    FOR(i, 1, n) { prefix[i] = prefix[i - 1] + (s[i - 1] - 'a' + 1) * power31[i - 1]; }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int ans = 0;
    initial();
    FOR(l, 1, n - m + 1)
    {
        if (t[0] != s[l - 1])
        {
            continue;
        }
        int r = l + m - 1;
        ll hashS = (prefix[r] - prefix[l - 1]);
        if (hashS == hashT * power31[l - 1])
        {
            ans++;
        }
    }
    cout << ans;
}