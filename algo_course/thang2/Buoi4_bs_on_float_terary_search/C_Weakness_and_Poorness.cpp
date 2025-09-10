#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int a[200'005];
double b[200'005], sum[200'005];
int n;
double f(double x)
{

    for (int i = 1; i <= n; i++)
        b[i] = a[i] - x;

    double sum = 0, ret = 0;
    double minL = 0, maxL = 0;
    // tìm maxSum = (sum[i] -minL) hoặc (maxL-sum[i])
    for (int i = 1; i <= n; i++)
    {
        sum += b[i];
        ret = max(ret, max(sum - minL, maxL - sum));
        minL = min(minL, sum);
        maxL = max(maxL, sum);
    }
    return ret;
}

void ternary_search()
{
    double lo = -10'005, hi = 10'005;
    int step = 500;
    while (step--)
    {
        double u = (2 * lo + hi) / 3, v = (2 * hi + lo) / 3;
        if (f(u) >= f(v))
            lo = u;
        else
            hi = v;
    }
    cout << fixed << setprecision(15) << f(lo);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ternary_search();
}