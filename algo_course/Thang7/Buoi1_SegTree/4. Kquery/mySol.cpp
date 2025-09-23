#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
const int inf = 1000000007;
int a[30'005];
vector<int> tree[4 * 30'005];
int n, t;
int l, r, k;
vector<int> merge(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0, n = a.size(), m = b.size();
    vector<int> res;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }
    while (i < n)
    {
        res.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        res.push_back(b[j]);
        j++;
    }
    return res;
}
void buildTree(int index, int L, int R)
{
    if (L == R)
    {
        tree[index].push_back(a[L]);
        return;
    }
    int mid = (L + R) / 2;
    buildTree(2 * index, L, mid);
    buildTree(2 * index + 1, mid + 1, R);
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

int getCnt(int index, int L, int R)
{
    if (l > R || L > r)
    {
        return 0;
    }
    if (l <= L && R <= r)
    {
        return tree[index].end() - upper_bound(ALL(tree[index]), k);
    }
    int mid = (L + R) / 2;
    int vLeft = getCnt(2 * index, L, mid);
    int vRight = getCnt(2 * index + 1, mid + 1, R);
    return (vLeft + vRight);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    buildTree(1, 1, n);
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> k;
        cout << getCnt(1, 1, n) << "\n";
    }
    return 0;
}