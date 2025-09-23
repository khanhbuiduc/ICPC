#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii; // open, close, pair
tiii tree[4'000'006];
int querys;
string str;
tiii merge(tiii l, tiii r) //
{
    auto [open_l, close_l, pair_l] = l;
    auto [open_r, close_r, pair_r] = r;
    int newPair = min(open_l, close_r);
    int pair = pair_l + pair_r + newPair;
    int open = open_l + open_r - newPair;
    int close = close_l + close_r - newPair;
    return {open, close, pair};
}

void buildTree(int i, int l, int r)
{
    if (l == r)
    {
        if (str[l] == '(')
            tree[i] = {1, 0, 0};
        else
            tree[i] = {0, 1, 0};
        return;
    }
    int mid = (l + r) / 2;
    buildTree(2 * i, l, mid);
    buildTree(2 * i + 1, mid + 1, r);
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}
tiii getPair(int i, int L, int R, int l, int r) // {l,r}
{
    if (R < l || r < L)
        return {0, 0, 0};
    if (l <= L && R <= r)
        return tree[i];
    int mid = (L + R) / 2;
    tiii left = getPair(2 * i, L, mid, l, r);
    tiii right = getPair(2 * i + 1, mid + 1, R, l, r);
    return merge(left, right);
}
int main()
{
    cin >> str;
    int n = str.length();
    str = '0' + str;
    buildTree(1, 1, n);
    cin >> querys;
    while (querys--)
    {
        int l, r;
        cin >> l >> r;
        tiii Node = getPair(1, 1, n, l, r);
        cout << (get<2>(Node) * 2) << endl;
    }
}

/*
())(())(())(
node: tiii: open dư, close dư, pair
khi gộp left_backets, right_backets;

xét cur:
pair cur = pair(left_backets + right_backets) + min(left_open + right_close)
close = left.close +right.close - min(left_open + right_close);
open = left.open +right.open - min(left_open + right_close);
*/