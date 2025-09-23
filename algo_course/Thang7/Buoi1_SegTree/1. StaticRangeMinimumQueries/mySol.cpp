#include <iostream>
#include <math.h>
const int inf = 1000000007;
int a[200005];
int tree[4 * 200005];
using namespace std;
int n, t;

void buildTree(int index, int L, int R)
{
    if (L == R)
    {
        tree[index] = a[L];
        return;
    }
    int mid = (L + R) / 2;
    buildTree(2 * index, L, mid);
    buildTree(2 * index + 1, mid + 1, R);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int getMin(int index, int L, int R, int l, int r)
{
    if (l > R || L > r)
    {
        return inf;
    }
    if (l <= L && R <= r)
    {
        return tree[index];
    }
    int mid = (L + R) / 2;
    int vLeft = getMin(2 * index, L, mid, l, r);
    int vRight = getMin(2 * index + 1, mid + 1, R, l, r);
    return min(vLeft, vRight);
}

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    buildTree(1, 1, n);
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << getMin(1, 1, n, l, r) << endl;
    }
    return 0;
}