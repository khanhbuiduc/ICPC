#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int fw[60'005], a[60'005];
void update(int index, int vals)
{
    for (; index <= 60'000; index += index & -index)
        fw[index] += vals;
}
ll get(int index)
{
    ll res = 0;
    for (; index > 0; index -= index & -index)
        res += fw[index];
    return res;
}
int main()
{
    int n;
    cin >> n;
    FOR(i, 1, n) { cin >> a[i]; }
    int ans = 0;
    FORD(i, n, 1)
    {
        ans += get(a[i] - 1); // tính tổng 1->a[i]
        update(a[i], 1);
    }
    cout << ans;
}
/*
cho a[1..n]: đếm số cặp nghịch thế.
 */