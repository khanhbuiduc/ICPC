#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int a[100'005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    FOR(i, 1, n) { cin >> a[i]; };
    sort(a + 1, a + n + 1);
    int i = n;
    for (i; i >= 1; i -= 2)
    {
        cout << a[i] << ' ';
    }
    i += 2;
    i = ((i == 1) ? 2 : 1);
    for (i; i <= n; i += 2)
    {
        cout << a[i] << ' ';
    }
    return 0;
}
/*
cho n người. người i có chiều cao h[i]
xếp chiều cao thành chữ v
ví dụ:
3 6 4 5 1 8 7 9 2
-> 9 7 5 3 1 2 4 6 8
=>max1 max3....min.....m4 m2

sort

duyệt i: n->1; i-=2
    in ra i
nếu i = 1 thì i=2;
nếu i = 2 thì i = 1;

duyệt i: i->n; i+= 2
    in ra i
*/