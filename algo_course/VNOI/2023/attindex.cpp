#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
using namespace std;
typedef long long ll;
const int inf = 1000000007;
string s;
int p, q;
int a[200005];
int n, numQueries;
struct node
{
    ll cnt;
    int len;
    int cntEven;
};
node it[4 * 200005];
node merge(node left, node right)
{
    node new_node;
    new_node.len = left.len + right.len;
    new_node.cntEven = left.cntEven + right.cntEven;
    new_node.cnt = left.cnt + right.cnt + (left.len * right.cntEven);
    return new_node;
}
void printNode(int index)
{
    auto [cnt, len, even] = it[index];
    cout << cnt << ' ' << len << ' ' << even << ' ' << endl;
}
void build(int index, int L, int R)
{
    if (L == R)
    {
        if ((a[L] % 2) == 0)
        {
            it[index] = node{1, 1, 1};
        }
        else
        {
            it[index] = node{0, 1, 0};
        }
        return;
    }
    int mid = (L + R) / 2;
    build(2 * index, L, mid);
    build(2 * index + 1, mid + 1, R);
    it[index] = merge(it[2 * index], it[2 * index + 1]);
}

node get(int index, int L, int R, int l, int r)
{
    if (l > R || L > r)
    {
        return node{0, 0, 0};
    }
    if (l <= L && R <= r)
    {
        return it[index];
    }
    int mid = (L + R) / 2;
    node vLeft = get(2 * index, L, mid, l, r);
    node vRight = get(2 * index + 1, mid + 1, R, l, r);
    return merge(vLeft, vRight);
}
void subtask1()
{
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // cout << l << r << endl;
        l--;
        r--;
        // Duyệt tất cả substring i-> j con trong đoạn này
        int ans = 0;
        FOR(i, l, r)
        FOR(j, i, r)
        {
            ll mod = 0;
            FOR(c, i, j)
            {
                (mod *= 10) %= p;
                (mod += (s[c] - '0')) %= p;
            }
            if (mod == 0)
                ans++;
        }
        cout << ans << endl;
    }
}
void subtask2()
{
    build(1, 1, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r).cnt << endl;
    }
}
int main()
{
    cin >> p >> s >> q;
    n = s.size();
    FOR(i, 1, n) { a[i] = s[i - 1] - '0'; };
    // FOR(i, 8, 15) { printNode(i); }
    if (n <= 100 && q <= 100)
    {
        subtask1();
    }
    else
    {
        subtask2();
    }
}