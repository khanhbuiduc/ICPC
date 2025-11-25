#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int n, a1, a2, b1, b2;
pii cap1, cap2;
bool check(ll x)
{
    // th1: a1 khám phá b1
    ll danger1, danger2, people1, people2;
    danger1 = a1 * b1, danger2 = a2 * b2;
    people1 = x / danger1, people2 = x / danger2;
    if (people1 + people2 >= n)
    {
        cap1 = {1, people1};
        cap2 = {2, n - people2};
        return true;
    }
    // th2: a2 khám phá b2
    danger1 = a1 * b2;
    danger2 = a2 * b1;
    people1 = x / danger1;
    people2 = x / danger2;
    if (people1 + people2 >= n)
    {
        ll actual1 = min(people1, (ll)n);
        cap1 = {1, actual1};
        cap2 = {2, n - actual1};
        return true;
    }

    return false;
}
ll bs()
{
    ll lo = 1, hi = 1e17;
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        if (check(mid)) // độ mạo hiểm mid thỏa mãn.
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> a1 >> a2 >> b1 >> b2;
    cout << bs() << endl;
    cout << cap1.ff << ' ' << cap1.ss << endl;
    cout << cap2.ff << ' ' << cap2.ss << endl;
}
