#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()

int n;
ll sum;
ll a[35];
bool used[35];
int best = INT_MAX; // biến lưu kết quả nhỏ nhất
int cnt = 0;
ll cursum = 0;
void backtrack(int idx)
{
    if (cursum == sum)
    {
        best = min(best, cnt);
        return;
    }

    if (cursum > sum || cnt >= best)
        return; // cắt nhánh

    for (int i = idx + 1; i <= n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            cnt++;
            cursum += a[i];
            backtrack(i);
            cnt--;
            used[i] = false;
            cursum -= a[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> sum;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }

    backtrack(0);

    if (best == INT_MAX)
        cout << -1;
    else
        cout << best;

    return 0;
}
