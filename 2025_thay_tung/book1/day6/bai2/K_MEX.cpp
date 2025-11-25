#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int cnt[100'000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector<long long> a(n);
    vector<long long> m(t);
    vector<long long> miss(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : m)
        cin >> x;
    for (int i = 0; i < n; i++)
        miss[i] = a[i] - i; // số lượng bị thiếu trước a[i]

    for (auto x : m)
    {
        // nếu x lớn hơn số bị thiếu trước a[n-1]
        if (x > miss[n - 1])
        {
            cout << a[n - 1] + (x - miss[n - 1]) << " ";
            continue;
        }

        int i = lower_bound(ALL(miss), x) - miss.begin();
        // tìm vị trí đầu tiên có missing[i] >= x
        long long res = a[i] - (miss[i] - x + 1);
        cout << res << " ";
    }
}
/*
1 2 6 7
a[0] = 1
gọi miss[i]: số phần tử thiếu trc a[i]
miss[0] = a[0] - 0 = 1
miss[1] = a[1] - 1 = 1
miss[2] = a[2] - 2 = 4
miss[3] = a[3] - 3 = 4
---
1 2 6 7
mex[5] = 7 + (5-4);
mex[i] > miss[n-1]
    => mex[i]  = a[n-1] + (mex[i] - miss[n-1])
----
mex[3] = 6 - 1 - (4 - 3)
mex[i] <=  miss[n-1]
    => tìm vị trí a[a] để
        miss[a]<mex[i] <= miss[a+1]
        lower_bound(miss, mex[i]) = miss[a+1]
        mex[i] = a[a+1] + 1 - (miss[a+1] - i)
*/