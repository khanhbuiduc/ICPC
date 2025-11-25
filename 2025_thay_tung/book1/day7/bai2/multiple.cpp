#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int a[200'005], sum[200'005]; // sum[i] = tổng a[1..i] % k;
map<int, int> store;          // map[i] = j: số i đã xuất hiện j lần.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    FOR(i, 1, n)
    {
        sum[i] = (sum[i - 1] + a[i]) % k;
    }
    ll ans = 0;
    FOR(i, 0, n)
    {
        ans += store[sum[i]];
        store[sum[i]]++;
    }
    cout << ans;
}
/*
cho a[1..n]
có bao nhiêu cặp (l..r) để sum[l..r]%k == 0
---
sum[i] = sum[1..i]
n< 10^5

5 3
1 2 3 4 5
------------

pre[]= 1 2 0 1 2
------------
đếm l->r xem có bao nhiêu số chia hết cho k.
 với mỗi l: đếm trc đó có bao nhiêu số
1 0 0 1 0
---
cnt[1] = 1;
a[1] = 0: cnt[0] = 0
    cnt++;
a[2] = 0:
    ans += cnt[0]
    cnt++;
---
sử dụng map<số, số lần xuất hiện> store.
---
}
*/