#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    FOR(i, 0, n - 1)
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    while (pq.size() >= 2)
    {
        ll min1 = pq.top();
        pq.pop();
        ll min2 = pq.top();
        pq.pop();
        if (min1 + min2 <= d)
        {
            pq.push(min1 + min2);
        }
        else
        {
            pq.push(min1);
            pq.push(min1);
            break;
        }
    }

    cout << d - pq.top();
}