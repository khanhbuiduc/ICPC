#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n;
int a[1000005], fw[1000005], smaller[1000005], bigger[1000005];
ll sumSmaller[1000005], rsumBigger[1000005];
void update(int index, int vals)
{
    for (; index <= 100'000; index += index & -index)
        fw[index] += vals;
}

ll get(int index) // trc index có bao nhiêu số < index.
{
    ll res = 0;
    for (; index > 0; index -= index & -index)
        res += fw[index];
    return res;
}

int main()
{
    cin >> n;
    FOR(i, 1, n) { cin >> a[i]; }
    FOR(i, 1, n)
    {
        smaller[a[i]] = (a[i] - 1) - (get(a[i] - 1));
        bigger[a[i]] = (i - 1) - (get(a[i] - 1));
        update(a[i], 1);
    }
    FOR(i, 1, n) { sumSmaller[i] = sumSmaller[i - 1] + smaller[i]; }
    FORD(i, n, 1) { rsumBigger[i] = rsumBigger[i + 1] + bigger[i]; }
    ll minVal = 1'000'000'000'000;
    FOR(i, 1, n)
    {
        minVal = min(minVal, sumSmaller[i - 1] + rsumBigger[i + 1]);
    }
    cout << minVal;
}

/*
chọn số a[i]
    những số <a[i] chuyển sang bên trái.
    những số >a[i] chuyển sang bên phải.
    đếm số lượng nghịch thế
=> trả về a[i] để số lượng nghịch thế min.

smaller[x]: số các số bên phải < x.
bigger[x]: số lượng các số bên trái > x.

số lượng nghịch thế = sum(smaller[2..x] + bigger[x..n-1])
--------
for i,1,n
    fw: đếm 1->a[i]: có bao nhiêu số đã xét.
    smaller[a[i]] = (total < a[i]) - số <a[i] bên trái.
    smaller[a[i]] = (a[i] - 1) - get(a[i] - 1)
    ---
    bigger[a[i]] = số bên trái - (số lượng smaller bên trái)
    bigger[a[i]] = i - 1 - get(a[i] - 1)
*/