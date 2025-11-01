#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, query;
ll power27[200'005];
string s;

struct itNode
{
    ll preSum = 0;
    ll sufSum = 0;
};

itNode it[4 * 200'005];

void build(int index, int L, int R)
{
    if (L == R)
    {
        it[index].preSum = (power27[L - 1] * (s[L - 1] - 'a'));
        it[index].sufSum = (power27[n - L] * (s[L - 1] - 'a'));
        return;
    }
    int mid = (L + R) >> 1;
    build(2 * index, L, mid);
    build(2 * index + 1, mid + 1, R);

    it[index].preSum = (it[2 * index].preSum + it[2 * index + 1].preSum);
    it[index].sufSum = (it[2 * index].sufSum + it[2 * index + 1].sufSum);
}

itNode get(int index, int L, int R, int l, int r)
{
    if (R < l || r < L)
        return {0, 0};
    if (l <= L && R <= r)
        return it[index];

    int mid = (L + R) >> 1;
    itNode left = get(2 * index, L, mid, l, r);
    itNode right = get(2 * index + 1, mid + 1, R, l, r);
    return {(left.preSum + right.preSum),
            (left.sufSum + right.sufSum)};
}

void update(int index, int l, int r, int pos, char val)
{
    if (l == r)
    {
        it[index].preSum = (power27[l - 1] * (val - 'a'));
        it[index].sufSum = (power27[n - l] * (val - 'a'));
        return;
    }
    if (pos < l || r < pos)
        return;

    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(2 * index, l, mid, pos, val);
    else
        update(2 * index + 1, mid + 1, r, pos, val);

    it[index].preSum = (it[2 * index].preSum + it[2 * index + 1].preSum);
    it[index].sufSum = (it[2 * index].sufSum + it[2 * index + 1].sufSum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> query >> s;

    power27[0] = 1;
    for (int i = 1; i <= n; i++)
        power27[i] = (power27[i - 1] * 27);

    build(1, 1, n);

    while (query--)
    {
        int type;
        cin >> type;

        if (type == 2)
        {
            int L, R;
            cin >> L >> R;
            auto [pre, suf] = get(1, 1, n, L, R);

            ll left_hash = (pre * power27[n - R]);
            ll right_hash = (suf * power27[L - 1]);

            cout << (left_hash == right_hash ? "YES" : "NO") << "\n";
        }
        else
        {
            int pos;
            char val;
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
    }
}