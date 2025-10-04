#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n, q;
int a[200'005];
ll tree[10][800'005];
bool checkNum(int num, int k)
{
    if (num % k == 0)
        return true;
    while (num)
    {
        if (num % 10 == k)
            return true;
        num /= 10;
    }
    return false;
}
void buildTree(int k, int index, int L, int R)
{
    if (L == R)
    {
        if (checkNum(L, k))
            tree[k][index] = 2 * a[L];
        else
            tree[k][index] = a[L];
        return;
    }
    int mid = (L + R) / 2;
    buildTree(k, 2 * index, L, mid);
    buildTree(k, 2 * index + 1, mid + 1, R);
    tree[k][index] = tree[k][2 * index] + tree[k][2 * index + 1];
}
void update(int k, int index, int L, int R, int pos, int val)
{
    if (L == R)
    {
        if (checkNum(pos, k))
            tree[k][index] = 2 * val;
        else
            tree[k][index] = val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
        update(k, 2 * index, L, mid, pos, val);
    else
        update(k, 2 * index + 1, mid + 1, R, pos, val);
    tree[k][index] = tree[k][2 * index] + tree[k][2 * index + 1];
}
ll getSum(int k, int index, int L, int R, int l, int r)
{
    if (l > R || r < L)
    {
        return 0;
    }
    if (l <= L && R <= r)
    {
        return tree[k][index];
    }
    int mid = (L + R) / 2;
    ll left = getSum(k, 2 * index, L, mid, l, r);
    ll right = getSum(k, 2 * index + 1, mid + 1, R, l, r);
    return left + right;
}
void initial()
{
    cin >> n >> q;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    FOR(k, 1, 9)
    {
        buildTree(k, 1, 1, n);
    }
}
int main()
{
    initial();
    int type, L, R, k, pos, val;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> pos >> val;
            FOR(k, 1, 9)
            {
                update(k, 1, 1, n, pos, val);
            }
        }
        else
        {
            cin >> L >> R >> k;
            cout << getSum(k, 1, 1, n, L, R) << endl;
        }
    }
    return 0;
}

/*

*/
/*
    n ban nho, ban i nhan duoc ai cai keo.
    chon k: 1->9
    cho keo ban i: L->R
        neu i%k==0 h
        oac i chua chu so k.
            ban i nhan duoc 2*ai cai keo
        else
            ban i nhan duoc ai cai keo
    ---
    query:
        1: thay doi so keo cua nguoi i -> c
        2: tinh tong: (L,R,k)
---
segment tree.
    tao 9 segment tree voi k 1->9
    voi query 1:
        cap nhap tree[1->9] i->c
    voi query 2:
        getSum(tree[k], L,R)
*/