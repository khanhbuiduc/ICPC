// https://codeforces.com/problemset/problem/1/A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m, a;
    cin >> n >> m >> a;
    int h = (n + a - 1) / a;
    int w = (m + a - 1) / a;
    ll result = 1ll * h * w;
    cout << result;
}