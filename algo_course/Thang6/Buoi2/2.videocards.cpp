#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;
/// template
typedef long long ll;
int n;
int cnt[200'005], pre_sum[200'005];
void initial()
{
    cin >> n;
    int x;
    FOR(i, 1, n)
    {
        cin >> x;
        cnt[x]++;
    }
    FOR(i, 1, 200'000)
    pre_sum[i] = pre_sum[i - 1] + cnt[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    initial();
    ll ans = 0;
    FOR(i, 1, 200'000)
    {
        if (cnt[i] == 0)
            continue;
        ll sum = 0;
        for (int j = i; j <= 200'000; j += i)
        {
            int r = min(200'000, j + i - 1);
            int l = j;
            sum += 1ll * j * (pre_sum[r] - pre_sum[l - 1]);
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
/*
4
3 2 15 9
----
n<200'000,ai<200'000
tính tổng sao cho bội chủa chúng lớn nhất:

x=2
2 2 14 8 sum= 26

x=3
3 0 15 9 sum= 27

x= 4
0 0 12 8 sum = 20
---
x=5:
1 2 3 4 5 6 7
0 0 0 0 1 1 1
0->x-1:0
x->2x-1:5

cnt[i] là số  lượng số có giá trị <i

for x:1->200'000
    sum = 0
    for j: x->200'000 ,j = j + x
        sum = sum + j*(cnt[j+x-1] - cnt[j-1]);
        max(ans,sum);
*/