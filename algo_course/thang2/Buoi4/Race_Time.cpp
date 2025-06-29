#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
vector<pii> a;
int n, k;
double f(double t)
{
    vector<double> P(n + 1);
    for (int i = 1; i <= n; i++)
        P[i] = a[i].ff * t + a[i].ss;
    auto minmaxDis = minmax_element(P.begin() + 1, P.end());
    return *minmaxDis.ss - *minmaxDis.ff;
}
void ternary_search()
{
    double lo = 0, hi = k;
    int step = 100;
    while (step--)
    {
        double u = (2 * lo + hi) / 3,
               v = (lo + 2 * hi) / 3;
        if (f(u) >= f(v))
            lo = u;
        else
            hi = v;
    }
    cout << fixed << setprecision(6) << f(lo);
}
int main()
{
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].ff >> a[i].ss;
    ternary_search();
}