#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("workout.inp", "r", stdin);
    freopen("workout.out", "w", stdout);
    int64_t n;
    cin >> n;
    int64_t sq = (int64_t)ceil(sqrt(n));

    sq *(sq - 1) >= n ? cout << sq + (sq - 1) : cout << 2 * sq;
}
