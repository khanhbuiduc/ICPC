#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("pile.inp", "r", stdin);
    freopen("pile.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, D, H;
    vector<int> arr;
    vector<int> dp;
    cin >> n >> D >> H;
    arr.resize(n);
    for (int &i : arr)
        cin >> i;

    dp.assign(n, INT_MAX);
    dp[0] = arr[0];

    // Sử dụng quy hoạch động để tính giá trị nhỏ nhất
    for (int i = 0; i < n; ++i)
    {
        if (dp[i] == INT_MAX)
            continue; // Bỏ qua các vị trí không thể đạt tới

        for (int step = 1; step <= D && i + step < n; ++step)
        {
            int nextIndex = i + step;
            if (abs(arr[nextIndex] - arr[i]) <= H)
            {
                dp[nextIndex] = min(dp[nextIndex], dp[i] + arr[nextIndex]);
            }
        }
    }

    int ans = dp[n - 1];
    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}
