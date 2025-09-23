#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;
struct itnode
{
    int totalPapers;
    itnode *left, *right;
    itnode() : totalPapers(0), left(nullptr), right(nullptr) {};
};

vector<itnode *> version;
int p[200005];
int n, numQueries;

void build(itnode *&root, int L, int R)
{
    root = new itnode();
    if (L == R)
    {
        return;
    }
    int mid = (L + R) / 2;
    build(root->left, L, mid);
    build(root->right, mid + 1, R);
}

void update(itnode *&root, int L, int R, int position)
{
    root = new itnode(*root);
    if (L == R)
    {
        root->totalPapers++;
        return;
    }
    int mid = (L + R) / 2;
    if (position <= mid)
        update(root->left, L, mid, position);
    else
        update(root->right, mid + 1, R, position);
    root->totalPapers = root->left->totalPapers + root->right->totalPapers;
}

int get(itnode *l, itnode *r, int L, int R, int more)
{
    if (L == R)
    {
        return L;
    }
    int mid = (L + R) / 2;
    int numbLarge = r->right->totalPapers - l->right->totalPapers;
    if (numbLarge + more >= mid + 1)
    {
        return get(l->right, r->right, mid + 1, R, more);
    }
    return get(l->left, r->left, L, mid, more + numbLarge);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> numQueries;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    itnode *root;
    build(root, 1, 200000);
    version.push_back(root);

    for (int i = 1; i <= n; i++)
    {
        update(root, 1, 200000, p[i]);
        version.push_back(root);
    }

    for (int query = 1; query <= numQueries; query++)
    {
        int L, R;
        cin >> L >> R;
        // tìm số lớn thứ h.
        int ans = get(version[L - 1], version[R], 1, 200000, 0);
        cout << ans << '\n';
    }

    return 0;
}