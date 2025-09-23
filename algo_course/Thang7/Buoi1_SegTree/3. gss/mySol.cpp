#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;
typedef tuple<int, int, int, int> tiiii; // maxL, maxR, maxSum, sum
tiiii tree[4 * 50'005];
int querys;
const int inf = -1'000'000'007;
int a[50'005];

tiiii merge(tiiii l, tiiii r)
{
    auto [maxL_L, maxR_L, maxSum_L, sum_L] = l;
    auto [maxL_R, maxR_R, maxSum_R, sum_R] = r;

    int maxSum = max({maxSum_L, maxSum_R, maxR_L + maxL_R});
    int maxL = max(maxL_L, sum_L + maxL_R);
    int maxR = max(maxR_R, sum_R + maxR_L);
    int sum = sum_L + sum_R;

    return {maxL, maxR, maxSum, sum};
}

void buildTree(int i, int l, int r)
{
    if (l == r)
    {
        tree[i] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l + r) / 2;
    buildTree(2 * i, l, mid);
    buildTree(2 * i + 1, mid + 1, r);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

tiiii getMaxSum(int i, int L, int R, int l, int r)
{
    if (R < l || r < L)
        return {inf, inf, inf, 0};
    if (l <= L && R <= r)
        return tree[i];
    int mid = (L + R) / 2;
    tiiii left = getMaxSum(2 * i, L, mid, l, r);
    tiiii right = getMaxSum(2 * i + 1, mid + 1, R, l, r);
    return merge(left, right);
}

int main()
{
    int n;
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    buildTree(1, 1, n);
    cin >> querys;
    while (querys--)
    {
        int l, r;
        cin >> l >> r;
        tiiii Node = getMaxSum(1, 1, n, l, r);
        cout << get<2>(Node) << endl;
    }
    return 0;
}