#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    ll minLoss = 10'000'000'000'000'007;
    cin >> n;
    ll value;
    multiset<ll> store;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        auto lower = store.lower_bound(value);
        if (lower != store.end())
        {
            minLoss = min(minLoss, *lower - value);
        }
        store.insert(value);
    }
    cout << minLoss;
}
/*
    // price=[20,15,8,2,12]: mua ở i, bán ở j: i<j
    1: price[i]<=price[j];
    2: store: lưu trữ những số đã gặp: để lấy lowerbounds;
    - for p:prices
        - tìm số >= p trong store;
        - nếu có thì tính min;
*/