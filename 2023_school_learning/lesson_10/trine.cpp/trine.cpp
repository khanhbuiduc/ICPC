#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    freopen("trine.inp", "r", stdin);
    freopen("trine.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c - 3 * min(a, min(b, c));
}