#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define __builtin_popcount __builtin_popcountll
using namespace std;
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}
/// template
int n;
int a[100'005];
int subset[3];
int f1[100'005], f2[100'005], f3[100'005]; //

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i];
    f1[1] = a[1];
    f2[2] = f1[1] + 2 * a[2];
    f3[3] = f2[2] + 3 * a[3];
    for (int i = 1; i < n; i++)
        f1[i + 1] = max(f1[i], a[i + 1]);

    //---
    for (int i = 2; i <= n; i++)
        f2[i + 1] = max(f2[i], f1[i] + 2 * a[i + 1]);

    //---
    for (int i = 3; i <= n; i++)
        f3[i + 1] = max(f3[i], f2[i] + 3 * a[i + 1]);
    //---
    cout << f3[n];
}
//
// f1[i] = max ai khi xét đến vị trí thứ i
// f2[i] = max ai + 2* aj  khi xét đến vị trí thứ i
// f3[i] = max ai + 2* aj + 3 ak khi xét đến vị trí thứ i

/*bài toán cơ sở:
    f1[1] = a[1];
    f2[2] = a[1] + 2 * a[2]
    f3[2] = a[1] + 2 * a[2] + 3 * a[3]

QHD f1
    for 2->n
        f1[i] = max (f[i-1], a[i])
QHD f2
    for 3->n
    bỏ qua số i
        f2[i] =  f2[i - 1]
    số i là aj
        f2[i] = 2*aj + ai =2* a[i] + f1[i - 1];

-1 2
f[2] = 3;
-2:
f[3] = f[2]
f[3] = f1[2] +  2*-2
*/
/*



f1[1] = a[1]
------------
qhd:
    xét số thứ i+1:
        f1[i+1] = max(f1[i], a[i+1]);
-------------
f2[2] = a[1] + a[2]
qhd:
    xét số thứ i+1:
    nếu dùng a[i+1];
        f2[i+1] = max(f2[i+1], dp1[i] + 2*a[i+1]​);
    nếu không dùng a[i+1]
        f2[i+1] = max(f2[i+1], f2[i]​);
-------------
f3[3] = a[1] + a[2] + f[3]
qhd:xét số thứ i+1:
    nếu dùng a[i+1];
        f3[i+1] = max(f3[i+1], dp2[j] + 3 * a[i+1]​);
    nếu không dùng a[i+1];
        f3[i+1] = max(f3[i+1], f3[i]​);
--------------
*/