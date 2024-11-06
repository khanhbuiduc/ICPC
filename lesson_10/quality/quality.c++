#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    freopen("quality.inp", "r", stdin);
    freopen("quality.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    int res = 0;
    for (int &i : arr)
        cin >> i;
    int l = 0, r = n - 1;
    while (l > r)
    {
        res++;
        while (l <= r && arr[l] != res)
            l++;
        while (l <= r && arr[r] != res)
            r--;
    }
    res = arr[l] == arr[r] ? res : res - 1;
    cout << res;
}