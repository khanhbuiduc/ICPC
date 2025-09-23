#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
int n, numQueries;
int a[100'005], b[100'005];
vector<pair<int, int>> vals;
struct Node
{
    Node *left;
    Node *right;
    ll cnt;
    Node() : cnt(0), left(nullptr), right(nullptr) {};
};
vector<Node *> version;
void buildTree(Node *&root, int L, int R)
{
    root = new Node();
    if (L == R)
    {
        // root->cnt = a[L];
        return;
    }
    int mid = (L + R) >> 1;
    buildTree(root->left, L, mid);
    buildTree(root->right, mid + 1, R);
    // root->cnt = root->left->cnt + root->right->cnt;
}
void update(Node *&root, int L, int R, int pos)
{
    root = new Node(*root);
    if (L == R)
    {
        root->cnt = 1;
        return;
    }
    int mid = (L + R) >> 1;
    if (pos <= mid)
        update(root->left, L, mid, pos);
    else
        update(root->right, mid + 1, R, pos);
    root->cnt = root->left->cnt + root->right->cnt;
}
ll get(Node *&rootLeft, Node *&rootRight, int L, int R, int k)
{
    if (L == R)
        return L;
    int mid = (L + R) >> 1;
    int sum_cnt = rootRight->left->cnt - rootLeft->left->cnt;
    if (sum_cnt >= k)
        return get(rootLeft->left, rootRight->left, L, mid, k);
    else
        return get(rootLeft->right, rootRight->right, mid + 1, R, k - sum_cnt);
}
void compress()
{
    sort(ALL(vals));
    FOR(i, 1, n)
    {
        auto [ai, pos] = vals[i - 1];
        b[pos] = i; // val based 0, b base 1.
    }
}
void initial()
{
    cin >> n >> numQueries;
    FOR(i, 1, n)
    {
        cin >> a[i];
        vals.emplace_back(a[i], i);
    }
    // compress a -> b
    compress();
    // create ver0;
    Node *ver0;
    buildTree(ver0, 1, n);
    version.push_back(ver0);
    // creat n tree remain
    FOR(i, 1, n)
    {
        Node *newVer = version[i - 1];
        update(newVer, 1, n, b[i]);
        version.push_back(newVer);
    }
}
int main()
{
    initial();
    while (numQueries--)
    {
        int L, R, k;
        cin >> L >> R >> k;
        int index = get(version[L - 1], version[R], 1, n, k);
        cout << vals[index - 1].first << endl;
    }
}

/*
 a[1 ... n]: 0<=a[i]<= tỉ

 query(L,R,k) tìm số lớn thứ k trong dãy a[l..r];

n+1 tree: quản lý đoạn 0->i với i<=n;
    mỗi node: quản lý khoảng [l..r] có bao nhiêu số trong dãy thỏa mãn.

tìm số thứ 5 trong đoạn [4..8]:
    - số lượng phần từ trong đoạn l->r:
        tree[8][l..r] - tree[3][l..r];
    => tìm số lớn thứ 5.
*/