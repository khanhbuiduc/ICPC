#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Query
{
    int l, r, id;
};
int BLOCK;
bool cmp(const Query &a, const Query &b)
{
    int A = a.l / BLOCK, B = b.l / BLOCK;
    if (A != B)
        return A < B;
    return (A & 1) ? (a.r > b.r) : (a.r < b.r);
}

void solve_p25(string &s, int p, vector<pair<int, int>> &queries)
{
    int n = s.size();
    vector<ll> cnt(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = cnt[i - 1] + ((s[i - 1] - '0') % p == 0);
        sum[i] = sum[i - 1] + cnt[i];
    }
    for (auto [L, R] : queries)
    {
        ll ans = sum[R] - sum[L - 1] - 1LL * (L - 1) * (cnt[R] - cnt[L - 1]);
        cout << ans << "\n";
    }
}

void solve_general(string &s, int p, vector<pair<int, int>> &queries)
{
    int n = s.size();
    vector<int> b(n + 2, 0);
    ll pow10 = 1;
    for (int i = n; i >= 1; i--)
    {
        b[i] = ((s[i - 1] - '0') * pow10 + b[i + 1]) % p;
        pow10 = (pow10 * 10) % p;
    }
    int q = queries.size();
    vector<Query> Q(q);
    for (int i = 0; i < q; i++)
        Q[i] = {queries[i].first, queries[i].second + 1, i};
    BLOCK = sqrt(n) + 1;
    sort(Q.begin(), Q.end(), cmp);

    vector<ll> ans(q), freq(p, 0);
    ll curAns = 0;
    int curL = 1, curR = 0;

    auto add = [&](int idx)
    { curAns += freq[b[idx]]; freq[b[idx]]++; };
    auto remove = [&](int idx)
    { freq[b[idx]]--; curAns -= freq[b[idx]]; };

    for (auto &qq : Q)
    {
        int L = qq.l, R = qq.r;
        while (curL > L)
            add(--curL);
        while (curR < R)
            add(++curR);
        while (curL < L)
            remove(curL++);
        while (curR > R)
            remove(curR--);
        ans[qq.id] = curAns;
    }
    for (auto x : ans)
        cout << x << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int p, q;
    cin >> s >> p >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++)
        cin >> queries[i].first >> queries[i].second;
    if (p == 2 || p == 5)
        solve_p25(s, p, queries);
    else
        solve_general(s, p, queries);
}
