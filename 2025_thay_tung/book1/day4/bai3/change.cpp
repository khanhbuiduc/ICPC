#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    cout << a + n - b;
}
/*

gọi h1, h2 là hướng dẫn viên 1,2
a[1..n] là khách.
ngồi ghế 1 hàng sao cho đầu và cuối là h1,h2

20  a=8 b=5

1 2 3 4 h2 6 7 h1 9 10 .. 19 20
h1: ở vị trí 8: 8 lượt đổi chỗ.
h2: ở vị trí 5 + 1 = 6: 15 cuộc đổi chỗ để đến cuối.
=> tổng 23
---
h1: a
h2: n - b

*/