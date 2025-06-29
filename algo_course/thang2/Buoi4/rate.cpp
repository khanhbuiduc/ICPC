#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int a[300'005];
double b[300'005], sum[300'005];
int n, k;
bool checkAvg(double avg)
{
    sum[0] = 0.0;
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - avg;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + b[i];
    double minL = sum[0];
    for (int i = k; i <= n; i++)
    {
        minL = min(minL, sum[i - k]);
        if (sum[i] >= minL)
            return true;
    }
    return false;
};
void binary_search()
{
    int step = 100;
    double lo = 0, hi = 1'000'000, ans = -1;
    while (step--)
    {
        double mid = (lo + hi) / 2;
        if (checkAvg(mid))
        {
            ans = mid;
            lo = mid;
        }
        else
            hi = mid;
    }
    cout << fixed << setprecision(6) << ans << "\n";
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    binary_search();
}
