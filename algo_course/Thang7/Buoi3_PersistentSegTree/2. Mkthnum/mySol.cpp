#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define ALL(v) (v).begin(), (v).end()
int n, numquery;
int a[100005], b[100005];
struct itnode
{
    itnode *left, *right;
    long long cnt = 0;
    itnode() : cnt(0), left(nullptr), right(nullptr) {}
};

void build(itnode *&root, int L, int R)
{
    root = new itnode();
    if (L == R)
        return;
    int mid = (L + R) / 2;
    build(root->left, L, mid);
    build(root->right, mid + 1, R);
}
void update(itnode *prev, itnode *&cur, int L, int R, int pos)
{
    cur = new itnode(*prev);
    if (L == R)
    {
        cur->cnt++;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
        update(prev->left, cur->left, L, mid, pos);
    else
        update(prev->right, cur->right, mid + 1, R, pos);
    cur->cnt = cur->left->cnt + cur->right->cnt;
}
int get(itnode *l, itnode *r, int L, int R, int k)
{
    if (L == R)
        return L;
    int mid = (L + R) / 2;
    int cnt = r->left->cnt - l->left->cnt;
    if (cnt >= k)
        return get(l->left, r->left, L, mid, k);
    else
        return get(l->right, r->right, mid + 1, R, k - cnt);
}

vector<pair<int, int>> temp;
void compress()
{
    sort(ALL(temp));
    for (int i = 0; i < n; i++)
    {
        auto [ai, pos] = temp[i];
        b[pos] = i + 1;
    }
}
int main()
{
    cin >> n >> numquery;
    FOR(i, 0, n - 1)
    {
        cin >> a[i];
        temp.emplace_back(a[i], i);
    }
    compress();
    vector<itnode *> version(n + 1);
    itnode *root0;
    build(root0, 1, n);
    version[0] = root0;
    FOR(i, 1, n)
    {
        update(version[i - 1], version[i], 1, n, b[i - 1]);
    }
    while (numquery--)
    {
        int L, R, k;
        cin >> L >> R >> k;
        int idx = get(version[L - 1], version[R], 1, n, k);
        cout << temp[idx - 1].first << endl;
    }
}