#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int f[100'005];
int h[100'005];
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    f[1] = 0;
    f[2] = abs(h[2] - h[1]);
    for (int i = 3; i <= n; i++)
    {
        f[i] = min(f[i - 1] + abs(h[i - 1] - h[i]), f[i - 2] + abs(h[i - 2] - h[i]));
    }
    cout << f[n];
}