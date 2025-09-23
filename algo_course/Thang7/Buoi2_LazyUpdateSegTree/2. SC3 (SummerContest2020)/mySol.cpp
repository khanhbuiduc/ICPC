#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pii;
vector<pair<int, int>> queries;
const int maxP = 4 * 100'005;
struct Node
{
    bool isCover;
};
Node tree[maxP];
void lazyUpdate(int index, int l, int r)
{
    if (tree[index].isCover && l < r)
    {
        tree[2 * index].isCover = true;
        tree[2 * index + 1].isCover = true;
    }
}
void update(int index, int L, int R, int x, int y)
{
    lazyUpdate(index, L, R);

    if (x > R || L > y)
    {
        return;
    }

    if (x <= L && R <= y)
    {
        tree[index].isCover = true;
        lazyUpdate(index, L, R);
        return;
    }

    int mid = (L + R) / 2;
    update(2 * index, L, mid, x, y);
    update(2 * index + 1, mid + 1, R, x, y);
    tree[index].isCover = (tree[2 * index].isCover && tree[2 * index + 1].isCover);
}

bool get(int index, int L, int R, int x, int y)
{
    lazyUpdate(index, L, R);

    if (x > R || L > y)
    {
        return true;
    }

    if (x <= L && R <= y)
    {
        return tree[index].isCover;
    }

    int mid = (L + R) / 2;
    bool vLeft = get(2 * index, L, mid, x, y);
    bool vRight = get(2 * index + 1, mid + 1, R, x, y);
    return (vLeft && vRight);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t, m, n, l, r;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int ans = 0;
        // clear
        queries.clear();
        FOR(i, 1, 4 * m)
        {
            tree[i].isCover = false;
        }
        FOR(i, 1, n)
        {
            cin >> l >> r;
            queries.push_back({l, r});
        }
        reverse(ALL(queries));
        for (auto [l, r] : queries)
        {
            if (!get(1, 1, m, l, r))
            {
                ans++;
                update(1, 1, m, l, r);
            }
        }

        cout << ans << endl;
    }
}

/*
tree: n=bitset thể hiện số màu
tree[i] = tree[2*i] | tree[2*i+1];

kết quả

count tree[i];
*/