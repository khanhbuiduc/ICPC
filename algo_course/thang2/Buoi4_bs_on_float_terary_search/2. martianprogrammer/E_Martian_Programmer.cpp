#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int H, A;
double f(double x)
{
    if (3 * x >= H)
        return 100;
    else if (6 * x >= H)
        return (600 - 6 * A) * x / H + (2 * A - 100);
    else
        return 6 * A * x / H;
}
double g(double x)
{
    return f(x) * (H - x);
}
void ternary_search()
{
    double lo = 0, hi = H;

    int step = 100;
    while (step--)
    {
        double u = (2 * lo + hi) / 3;
        double v = (lo + 2 * hi) / 3;
        if (g(u) > g(v))
            hi = v;
        else
            lo = u;
    }
    cout << fixed << setprecision(8) << g(lo);
}
int main()
{
    cin >> A >> H;
    ternary_search();
}