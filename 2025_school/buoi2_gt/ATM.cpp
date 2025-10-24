#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n, sum;
int a[25];
int used[25];
bool haveAns = false;
void backtrack(int cursum)
{
    if (haveAns)
        return;
    if (cursum == sum)
    {
        FOR(i, 1, n)
        {
            if (used[i])
                cout << a[i] << " ";
        }
        cout << "\n";
        haveAns = true;
        return;
    }
    FOR(i, 1, n)
    {
        if (!used[i] && cursum + a[i] <= sum)
        {
            used[i] = 1;
            backtrack(cursum + a[i]);
            used[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> sum;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    backtrack(0);
    return 0;
}