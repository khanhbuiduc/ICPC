/*
Fenwick Tree:
    query 1: increase f[x] by k units.
    query 2: calculate sum(f[1->i]);

ICPC 2021 Southern Vietnam - I: Inversion Number
Choose number a[i]
    numbers < a[i] move to the left.
    numbers > a[i] move to the right.
    count inversions
=> return a[i] to minimize inversions.
*/

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
    for (; index <= 1000000; index += index & -index)
        fw[index] += vals;
}

ll get(int index)
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
        // update fw[a[i]] = 1
        update(a[i], 1);
    }
    FOR(i, 1, n) { sumSmaller[i] = sumSmaller[i - 1] + smaller[i]; }
    FORD(i, n, 1) { rsumBigger[i] = rsumBigger[i + 1] + bigger[i]; }
    ll minVal = 1000000000000;
    FOR(i, 1, n)
    {
        minVal = min(minVal, sumSmaller[i - 1] + rsumBigger[i + 1]);
    }
    cout << minVal;
}

/*
smaller[x]: number of elements to the right < x.
bigger[x]: number of elements to the left > x.

inversions = sum(smaller[2..x] + bigger[x..n-1])
--------
for i,1,n
    fw: count 1->a[i]: how many numbers processed.
    smaller[a[i]] = (total < a[i]) - numbers <a[i] on left.
    smaller[a[i]] = (a[i] - 1) - get(a[i] - 1)
    ---
    bigger[a[i]] = left numbers - (smaller numbers on left)
    bigger[a[i]] = i - 1 - get(a[i] - 1)
*/