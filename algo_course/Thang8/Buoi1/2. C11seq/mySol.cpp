#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()

int n;
ll maxVal, minVal;
vector<ll> a;

ll mergeCount(int L, int R, int mid)
{
    ll cnt = 0;
    vector<ll> suf_left, pre_right;

    // --- tính suffix sum bên trái ---
    ll sum = 0;
    FORD(i, mid, L)
    {
        sum += a[i];
        suf_left.push_back(sum);
    }
    sort(ALL(suf_left));

    // --- tính prefix sum bên phải ---
    sum = 0;
    FOR(i, mid + 1, R)
    {
        sum += a[i];
        pre_right.push_back(sum);
    }

    // --- đếm số cặp ---
    for (ll ri : pre_right)
    {
        // ta cần left sao cho minVal ≤ left + ri ≤ maxVal
        auto it1 = lower_bound(ALL(suf_left), minVal - ri);
        auto it2 = upper_bound(ALL(suf_left), maxVal - ri);
        it2--;
        cnt += (it2 - it1 + 1);
    }

    return cnt;
}

ll solve(int L, int R)
{
    if (L == R)
    {
        return (a[L] >= minVal && a[L] <= maxVal);
    }
    int mid = (L + R) / 2;
    ll left = solve(L, mid);
    ll right = solve(mid + 1, R);
    return left + right + mergeCount(L, R, mid);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n >> minVal >> maxVal;
    a.resize(n + 1);
    FOR(i, 1, n)
    cin >> a[i];

    cout << solve(1, n);
}

/*
Input:
4 2 4
1 2 3 4

Output:
4

Các đoạn hợp lệ:
[2] = 2
[3] = 3
[1,2] = 3
[4] = 4
*/
