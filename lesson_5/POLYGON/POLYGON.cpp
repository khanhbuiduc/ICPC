#include <bits/stdc++.h>

using namespace std;
#define NAME "polygon."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
int n;
double s = 0, a, b;
int main()
{
    fi >> n;
    vector<double> x(n + 1), y(n + 1);
    for (int i = 0; i < n; i++)
        fi >> x[i] >> y[i];
    x[n] = x[0];
    y[n] = y[0];
    for (int i = 0; i < n; i++)
        s += x[i] * y[i + 1] - x[i + 1] * y[i];
    s = abs(s) / 2;
    fo << fixed << setprecision(6) << s;
}