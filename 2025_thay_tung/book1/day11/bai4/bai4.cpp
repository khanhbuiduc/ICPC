#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
pii hcn[100'005];
vector<pii> ans;
int n;
void dfs(int index, pii cur)
{
    if (index == n)
    {
        ans.push_back(cur);
        return;
    }
    auto [a, b] = cur;
    auto [n_a, n_b] = hcn[index + 1];
    if (a == n_a && b + n_b != a)
        dfs(index + 1, {a, b + n_b});
    if (a == n_b && b + n_a != a)
        dfs(index + 1, {a, b + n_a});
    if (b == n_a && a + n_b != b)
        dfs(index + 1, {a + n_b, b});
    if (b == n_b && a + n_a != b)
        dfs(index + 1, {a + n_a, b});
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> hcn[i].ff >> hcn[i].ss;
    }
    dfs(1, hcn[1]);
    cout << ans.size() << endl;
    for (auto [a, b] : ans)
        cout << a << ' ' << b << endl;
    return 0;
}