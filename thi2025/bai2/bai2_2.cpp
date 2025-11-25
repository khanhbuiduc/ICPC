#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
bool can = false;
bool haveStop = false;
vector<int> a;
ll n, d;
void backtrack(int index, vector<ll> hole)
{
    if (haveStop)
        return;
    FOR(i, 0, hole.size() - 1)
    {
        if (hole[i] + a[index] > d)
            continue;

        hole[i] += a[index];

        if (index == n - 1)
        {
            can = true;
            haveStop = true;
            return;
        }
        backtrack(index + 1, hole);
        hole[i] -= a[index];
    }
}
bool check(int numDCD)
{
    can = false;
    haveStop = false;
    vector<ll> hole(numDCD, 0);
    backtrack(0, hole);
    return can;
}
// liệu có thể tìm đc tổng <= x không.
void binary_search_on_answer(int li, int hi)
{
    int ans = 0;
    while (li <= hi)
    {
        int mid = (li + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            li = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n >> d;
    a.resize(n);
    FOR(i, 0, n - 1)
    {
        cin >> a[i];
    }
    sort(ALL(a));
    binary_search_on_answer(1, n);
}
/*
d = 5
1 2 2 4 5
1: 1 2 2
2: 4
3: 5
*/