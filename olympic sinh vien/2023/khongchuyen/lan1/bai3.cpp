#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int pre[1'000'005][27];
int n, q;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> q;
    cin >> s;
    FOR(i, 1, n)
    {
        int ci = s[i - 1] - 'a';
        pre[i][ci] = 1;
    }
    FOR(i, 1, n)
    {
        FOR(ci, 0, 25)
        {
            pre[i][ci] += pre[i - 1][ci];
            // cout << pre[i][ci] << ' ';
        }
        // cout << endl;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l++, r++;
        int cnt = 0; // đếm xem có bao nhiêu ký tự lẻ.
        FOR(ci, 0, 25)
        {
            if (((pre[r][ci] - pre[l - 1][ci]) & 1) == 1) // nếu lẻ
                cnt++;
        }
        cout << ((cnt) / 2) << endl;
    }
}