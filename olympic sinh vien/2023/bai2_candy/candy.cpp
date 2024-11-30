#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n, q;
vector<vector<int64_t>> segmentTrees(10);
bool isValid(int number, int digit)
{
    if (number % digit == 0)
    {
        return true;
    }
    while (number > 0)
    {
        if (number % 10 == digit)
        {
            return true;
        }
        number /= 10;
    }
    return false;
}
void buildTree(int i, int L, int R, int digit)
{
    if (L == R) // Leaf node
    {
        if (isValid(L, digit))
        {
            segmentTrees[digit][i] = 2 * a[L];
        }
        else
        {
            segmentTrees[digit][i] = a[L];
        }
    }
    else
    {
        int mid = (L + R) / 2;
        buildTree(2 * i, L, mid, digit);
        buildTree(2 * i + 1, mid + 1, R, digit);
        segmentTrees[digit][i] = segmentTrees[digit][2 * i] + segmentTrees[digit][2 * i + 1];
    }
}
void update(int i, int l, int r, const int &position, const int &val, int digit)
{
    if (position < l || r < position)
        return;
    if (l == r)
    {
        if (isValid(position, digit))
        {
            segmentTrees[digit][i] = 2 * val;
        }
        else
        {
            segmentTrees[digit][i] = val;
        }
    }
    else
    {
        int mid = (l + r) / 2;
        update(2 * i, l, mid, position, val, digit);
        update(2 * i + 1, mid + 1, r, position, val, digit);
        segmentTrees[digit][i] = segmentTrees[digit][2 * i] + segmentTrees[digit][2 * i + 1];
    }
}
int64_t sumRange(int i, int L, int R, int l, int r, int digit)
{
    if (r < L || R < l)
    {
        return 0;
    }
    if (l <= L && R <= r)
    {
        return segmentTrees[digit][i];
    }
    int mid = (L + R) / 2;
    int64_t valueLeft = sumRange(2 * i, L, mid, l, r, digit);
    int64_t valueRight = sumRange(2 * i + 1, mid + 1, R, l, r, digit);
    return valueLeft + valueRight;
}
int main()
{
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);

    cin >> n >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int digit = 1; digit <= 9; digit++)
    {
        segmentTrees[digit].resize(4 * n);
        buildTree(1, 1, n, digit);
    }
    int type;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            int i, c;
            cin >> i >> c;
            for (int digit = 1; digit <= 9; digit++)
            {
                update(1, 1, n, i, c, digit);
            }
        }
        else
        {
            int L, R, k;
            cin >> L >> R >> k;
            cout << sumRange(1, 1, n, L, R, k) << endl;
        }
    }
    return 0;
}