#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int p, q, n;
string s;
int pre[100'005];
map<int, int> it[4 * 100'005];
map<int, int> merge(map<int, int> L, map<int, int> R)
{
    map<int, int> res;
    for (auto [num, cnt] : L)
        res[num] += cnt;
    for (auto [num, cnt] : R)
        res[num] += cnt;
    return res;
}
map<int, int> build(int index, int L, int R) // 0->n
{
    if (L == R)
    {
        it[index][pre[L]] = 1;
    }
    else
    {
        int mid = (L + R) >> 2;
        auto left = build(2 * index, L, mid);
        auto right = build(2 * index + 1, mid + 1, R);
        it[index] = merge(left, right);
    }
}

map<int, int> get(int index, int L, int R, int l, int r) // 0->n
{
    if (l <= L && R <= r)
        return it[index];
    else
    {
        int mid = (L + R) >> 2;
        auto left = get(2 * index, L, mid, l, r);
        auto right = get(2 * index + 1, mid + 1, R, l, r);
        return merge(left, right);
    }
}

void initial()
{
    pre[0] = 0;
    FOR(i, 1, n) { pre[i] = (pre[i - 1] + s[i - 1]) % p; }
    build(1, 0, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> p >> s >> q;
    n = s.length();
    // pre
    pre[0] = 0;
    FOR(i, 1, n) { pre[i] = (pre[i - 1] + s[i - 1]) % p; }

    initial();
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        auto cnt = get(1, 1, n, L, R);
    }
}