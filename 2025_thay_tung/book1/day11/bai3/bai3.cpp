#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int inf = 1e9 + 7;
int a[500'005], p[250'005];
int n;
struct node
{
    int min = inf;
    int max = -1;
};
node it[4 * 500'005];
void build(int index, int L, int R)
{
    if (L == R)
    {
        it[index].min = p[L];
        it[index].max = p[L];
        return;
    }
    int mid = (L + R) / 2;
    build(2 * index, L, mid);
    build(2 * index + 1, mid + 1, R);
    it[index].min = min(it[2 * index].min, it[2 * index + 1].min);
    it[index].max = max(it[2 * index].max, it[2 * index + 1].max);
}
void update(int index, int L, int R, int pos, int val)
{
    if (L == R)
    {
        it[index].min = val;
        it[index].max = val;
        return;
    }
    int mid = (L + R) >> 1;
    if (pos <= mid)
        update(2 * index, L, mid, pos, val);
    else
        update(2 * index + 1, mid + 1, R, pos, val);
    it[index].min = min(it[2 * index].min, it[2 * index + 1].min);
    it[index].max = max(it[2 * index].max, it[2 * index + 1].max);
}
void printtree()
{
    FOR(i, 1, 2 * n)
    {
        cout << it[i].min << ' ' << it[i].max << endl;
    }
    cout << "_____" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n) { cin >> a[i]; }
    sort(a + 1, a + n + 1);
    // ban đầu a[n] làm quản trò.
    FOR(i, 1, n / 2)
    {
        p[i] = (a[i] + a[n - i]);
    }
    build(1, 1, n / 2);
    int ans = (it[1].max - it[1].min);
    // update cặp 1->n/2
    FOR(i, 1, n / 2)
    {
        // vd p[1] = a[1] + a[9]
        // vd p[1] = a[2] + a[8]
        p[i] = (a[i] + a[n - i + 1]);
        update(1, 1, n, i, p[i]);
        ans = min(ans, it[1].max - it[1].min);
    }
    // update cặp n/2 ->1;
    FORD(i, n / 2, 1)
    {
        // vd p[4] = a[5] + a[6]
        // vd p[3] = a[4] + a[7]
        p[i] = (a[i + 1] + a[n - i]);
        update(1, 1, n, i, p[i]);
        ans = min(ans, it[1].max - it[1].min);
    }
    cout << ans;
    return 0;
}
/*
5
1 2 3 4 5 6 7 8 9 10 11
---
từ 2->n ghép cặp
ghép cặp min mới max là tối ưu nhất
(2 11) (3,10) (4,9) (5,8) (6,7)
13 13 13 13 13
-> min = 13
-----------------------------------
(2 11) (3,10) (4,9) (5,8) (6,7)
-----------------------------------
n học sinh -> n/2 cặp, 1 quản trò

tìm minmax của tất cả các cặp.

tìm min max
(2 11) (3,10) (4,9) (5,8) (6,7)
--
update đổi người 1 vào cặp 1.
(1 11) (3,10) (4,9) (5,8) (6,7)
=> minmax tìm min max
--
update đổi người 2 vào cặp 2.
(1 11) (3,10) (4,9) (5,8) (6,7)
=> minmax tìm min max
--
-----
in ra chenh lệch min
*/