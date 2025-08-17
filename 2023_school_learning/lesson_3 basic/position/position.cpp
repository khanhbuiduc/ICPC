#include <bits/stdc++.h>
using namespace std;
ifstream fi("input");
ofstream fo("output");

int main()
{
    float u, v, x1, x2, y1, y2, d;
    fi >> u >> v >> x1 >> y1 >> x2 >> y2;
    string vz[9] = {"sw", "s", "se", "w", "0", "e", "nw", "n", "ne"};
    int a, b, z;
    if (u > x2)
    {
        a = 0;
    }
    else if (u >= x1)
    {
        a = 1;
    }
    else
    {
        a = 2;
    }
    if (v > y2)
    {
        b = 0;
    }
    else if (v >= y1)
    {
        b = 1;
    }
    else
    {
        b = 2;
    }
    z = 3 * b + a;
    switch (z)
    {
    case 0:
        d = sqrt((u - x2) * (u - x2) + (v - y2) * (v - y2));
        break;
    case 1:
        d = v - y2;
        break;
    case 2:
        d = sqrt((u - x1) * (u - x1) + (v - y2) * (v - y2));
        break;
    case 3:
        d = u - x2;
        break;
    case 5:
        d = x1 - u;
        break;
    case 6:
        d = sqrt((u - x2) * (u - x2) + (v - y1) * (v - y1));
        break;
    case 7:
        d = y1 - v;
        break;
    case 8:
        d = sqrt((u - x1) * (u - x1) + (v - y1) * (v - y1));
        break;
    }
    cout << vz[z] << " " << fixed << setprecision(4) << d;
    fo << d;
}