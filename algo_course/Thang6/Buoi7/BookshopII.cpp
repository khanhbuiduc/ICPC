#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
using namespace std;
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
/// template
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
int n, x;
vector<pii> books;    // p,w
int f[1105][100'005]; // imax = 11*100; wmax = x_max
int h[105], s[105], k[105];
void add_book(int p, int w, int cnt)
{
    int pow2 = 1;
    while (cnt > 0)
    {
        int take = min(pow2, cnt);
        books.emplace_back(p * take, w * take);
        pow2 <<= 1;
        cnt -= take;
    }
}
// ...existing code...
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int p, w, cnt;
    cin >> n >> x;
    books.clear(); // Xóa phần tử giả nếu có
    FOR(i, 1, n) { cin >> h[i]; }
    FOR(i, 1, n) { cin >> s[i]; }
    FOR(i, 1, n) { cin >> k[i]; }
    FOR(i, 1, n)
    {
        add_book(h[i], s[i], k[i]);
    }
    n = books.size();
    FOR(i, 0, n)
    FOR(p, 0, x)
    {
        f[i][p] = -1;
    }
    FOR(i, 0, n) { f[i][0] = 0; }
    FOR(p, 0, x) { f[0][p] = 0; }
    // qhd
    FOR(i, 0, n - 1)
    FOR(p, 0, x)
    {
        if (f[i][p] == -1)
            continue;
        // Không lấy sách i
        maximize(f[i + 1][p], f[i][p]);
        // Lấy sách i nếu đủ giá
        if (p + books[i].ff <= x)
            maximize(f[i + 1][p + books[i].ff], f[i][p] + books[i].ss);
    }
    int ans = 0;
    FOR(p, 0, x)
    maximize(ans, f[n][p]);
    cout << ans << "\n";
}