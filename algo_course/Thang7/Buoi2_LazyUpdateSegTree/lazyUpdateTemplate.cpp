#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;
typedef pair<int, int> pii;
const int maxP = 4 * 100'005;
struct Node
{
    int lazyValue;
    int maxValue;
};
Node tree[maxP];
void lazyUpdate(int index, int l, int r)
{
    if (tree[index].lazyValue > 0 && l < r)
    {
        tree[2 * index].lazyValue += tree[index].lazyValue;
        tree[2 * index].maxValue += tree[index].lazyValue;
        tree[2 * index + 1].lazyValue += tree[index].lazyValue;
        tree[2 * index + 1].maxValue += tree[index].lazyValue;
        tree[index].lazyValue = 0;
    }
}
void update(int index, int L, int R, int x, int y, int k)
{
    lazyUpdate(index, L, R);

    if (x > R || L > y)
    {
        return;
    }

    if (x <= L && R <= y)
    {
        tree[index].lazyValue += k;
        tree[index].maxValue += k;
        lazyUpdate(index, L, R);
        return;
    }

    int mid = (L + R) / 2;
    update(2 * index, L, mid, x, y, k);
    update(2 * index + 1, mid + 1, R, x, y, k);
    tree[index].maxValue = max(tree[2 * index].maxValue, tree[2 * index + 1].maxValue);
}

int get(int index, int L, int R, int x, int y)
{
    lazyUpdate(index, L, R);

    if (x > R || L > y)
    {
        return -1;
    }

    if (x <= L && R <= y)
    {
        return tree[index].maxValue;
    }

    int mid = (L + R) / 2;
    int vLeft = get(2 * index, L, mid, x, y);
    int vRight = get(2 * index + 1, mid + 1, R, x, y);
    return max(vLeft, vRight);
}