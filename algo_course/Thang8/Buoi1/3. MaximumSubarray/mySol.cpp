#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int a[100'005];
int merge(int L, int mid, int R)
{
    int max_Subleft = -1e9, max_Preright = -1e9;
    int sum = 0;
    FORD(i, mid, L)
    {
        sum += a[i];
        max_Subleft = max(max_Subleft, sum);
    }
    sum = 0;
    FOR(i, mid + 1, R)
    {
        sum += a[i];
        max_Preright = max(max_Preright, sum);
    }
    return max_Subleft + max_Preright;
}
int solve(int L, int R)
{
    if (L == R)
    {
        return a[L];
    }
    int mid = (L + R) >> 1;
    int left = solve(L, mid);
    int right = solve(mid + 1, R);
    return max({left, right, merge(L, mid, R)});
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        // tính subsequences
        int subsequences = 0;
        int maxVal = -1e5;
        FOR(i, 1, n)
        {
            cin >> a[i];
            maxVal = max(maxVal, a[i]);
            if (a[i] > 0)
                subsequences += a[i];
        }
        if ((maxVal < 0))
            subsequences = maxVal;
        // tính subarrays
        int subarrays = 0;
        cout << solve(1, n) << ' ';
        cout << subsequences << endl;
    }
}

/*
cho a[1..n]
    in ra:
        max: chuỗi con arr;
        max: chuỗi con;
tính subsequences
    -1, 2, 3, -4, 5, 10
    chỗi con arr: 2 + 3 - 4 + 5 + 10 = 16
    chuỗi con: 2 + 3 + 5 + 10 = 20
--------------------
tính subarray:
    chia arr làm 2 phần: tính max subarray bên trái và bên phải
    cur.max = left.max || right.max || max(left.subfix) + max(right.prefix)
    node: max;

*/