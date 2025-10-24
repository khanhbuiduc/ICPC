#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define M 1'000'000'007
typedef pair<int, int> pii;
typedef long long ll;
int n;
ll powerMod(int &a, int b) // tính a^b mod M
{
    if (b == 0)
        return 1;
    if (b & 1)
    {
        return (powerMod(a, b - 1) * a) % M;
    }
    else
    {
        ll ret = powerMod(a, b / 2);
        return (ret * ret) % M;
    }
}
int main()
{
    int t;
    int a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << powerMod(a, b) << "\n";
    }
}