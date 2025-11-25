#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
ll pre[1'000'005];
ll a[1'000'005];
ll pow27[1'000'005];
vector<string> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();

    pow27[0] = 1;
    FOR(i, 1, n)
    {
        pow27[i] = (pow27[i - 1] * 27);
    }

    FOR(i, 0, n - 1)
    {
        int c = (s[i] - 'a' + 1);
        a[i + 1] = (c * pow27[i]);
    }

    FOR(i, 1, n)
    {
        pre[i] = (pre[i - 1] + a[i]);
    }

    int l = 1, r = n;
    while (l < r)
    {
        int maxLen = (r - l + 1) / 2;
        bool found = false;

        FOR(len, 1, maxLen)
        {
            ll hash_left = pre[l + len - 1] - pre[l - 1];
            ll hash_right = pre[r] - pre[r - len];

            if (hash_left * pow27[r - len] == hash_right * pow27[l - 1])
            {
                ans.push_back(s.substr(l - 1, len));
                l += len;
                r -= len;
                break;
            }
        }
    }

    cout << ans.size() << endl;
    for (string i : ans)
    {
        cout << i << endl;
    }

    return 0;
}
/*
guesswhoitisisitwhoguess
*/