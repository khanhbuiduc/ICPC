/*
CSES Problem Set
Range Queries and Copies:

Given a[1..n].
    query 1: change value a[i] in array k to x.
    query 2: sum(a[l..r]) in array k
    query 3: add new version of array k.
*/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
using namespace std;
typedef long long ll;
int n, numQueries;
int a[200005];

struct Node
{
    Node *left;
    Node *right;
    ll sum;
    Node() : sum(0), left(nullptr), right(nullptr) {};
};
vector<Node *> version;

void BuildTree(Node *&root, int L, int R)
{
    root = new Node();
    if (L == R)
    {
        root->sum = a[L];
        return;
    }
    int mid = (L + R) >> 1;
    BuildTree(root->left, L, mid);
    BuildTree(root->right, mid + 1, R);
    root->sum = root->left->sum + root->right->sum;
}

void update(Node *&root, int L, int R, int pos, int val)
{
    root = new Node(*root);
    if (R < pos || L > pos)
        return;
    if (L == R)
    {
        root->sum = val;
        return;
    }
    int mid = (L + R) >> 1;
    if (pos <= mid)
        update(root->left, L, mid, pos, val);
    else
        update(root->right, mid + 1, R, pos, val);
    root->sum = root->left->sum + root->right->sum;
}

ll get(Node *&root, int L, int R, int l, int r)
{
    if (R < l || r < L)
        return 0;
    if (L >= l && r >= R)
        return root->sum;
    int mid = (L + R) >> 1;
    ll sum_L = get(root->left, L, mid, l, r);
    ll sum_R = get(root->right, mid + 1, R, l, r);
    return sum_L + sum_R;
}

void initial()
{
    cin >> n >> numQueries;
    FOR(i, 1, n)
    cin >> a[i];
    // Create seg tree for ver0
    Node *ver0 = new Node();
    version.push_back(ver0);
    BuildTree(version[0], 1, n);
}

int main()
{
    initial();
    while (numQueries--)
    {
        int type, k, val, pos, b, l, r;
        cin >> type >> k;
        k--;
        if (type == 1)
        {
            cin >> pos >> val;
            update(version[k], 1, n, pos, val);
        }
        else if (type == 2)
        {
            cin >> l >> r;
            cout << get(version[k], 1, n, l, r) << endl;
        }
        else if (type == 3)
        {
            Node *newVer = new Node(*version[k]);
            version.push_back(newVer);
        }
    }
}