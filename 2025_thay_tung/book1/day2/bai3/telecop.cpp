#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int a[100'005], pre[100'005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, r;
    cin >> n >> r;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    // pre[i]
    pre[0] = 0;
    FOR(i, 1, n) { pre[i] = pre[i - 1] + a[i]; }
    //
    FOR(i, 1, n)
    {
        int lo = 0, hi = n;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int L = max(1, i - mid);
            int R = min(n, i + mid);
            if (pre[R] - pre[L - 1] <= r)
            {
                lo = mid + 1;
                ans = mid;
            }
            else
                hi = mid - 1;
        }
        cout << ans << endl;
    };
}

/*
n=3 r=4
1 3 5

city 1:  k = 1 thìn thấy 4
city 2:  k = 0 nhìn thấy 3
city 3: k = -1 nhìn thấy 5

r 10

1 3 5 2 5 2 4 2 5
preSum[i]= sum[a[1..i]]
sufSum[i]: sum[s[1..i]]
xét vị trí i:
    k thỏa mãn:
        int L = i - k;
        int R = i + k;
        sum[L..R] = pre[R] - pre[L-1];
FOR(i,1,n){
    FOR(k,1,n){

    }
}

*/