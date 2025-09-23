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
void initial()
{
}
void solve()
{
}
int a[200'005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t, n, l, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> l >> r;
        FOR(i, 1, n)
        cin >> a[i];
        sort(a + 1, a + n + 1);

        long long ans = 0; // Reset ans cho mỗi test case và dùng long long

        FOR(i, 1, n - 1) // Sửa từ i=2 thành i=1 và i < n
        {
            // Tìm chỉ số đầu tiên j > i mà a[j] >= l - a[i]
            int minj = lower_bound(a + i + 1, a + n + 1, l - a[i]) - a;
            // Tìm chỉ số cuối cùng j > i mà a[j] <= r - a[i]
            int maxj = upper_bound(a + i + 1, a + n + 1, r - a[i]) - 1 - a;

            if (maxj >= minj)
                ans += (maxj - minj + 1);
        }
        cout << ans << "\n";
    }
}
/*
Thuật toán:
1. Sort mảng a
2. Với mỗi i từ 1 đến n-1:
   - Tìm range [minj, maxj] trong đoạn [i+1, n] sao cho:
     l <= a[i] + a[j] <= r
   - Tương đương: l - a[i] <= a[j] <= r - a[i]
   - Dùng binary search để tìm range này
3. Cộng số phần tử trong range vào kết quả

Time complexity: O(n log n) cho sort + O(n log n) cho binary search = O(n log n)
*/