/////////////////đọc đề cẩn thận như bài này k để ý đọc nhần i với a[i] làm rất mất thời gian

#include <bits/stdc++.h>
using namespace std;
int n, p, k;
vector<vector<int64_t>> tree(10);
vector<int> a;
bool isDouble(int number, int k)
{
    if (number % k == 0)
        return true;
    while (number > 0)
    {
        if (number % 10 == k)
            return true;
        number /= 10;
    }
    return false;
}
void buildTree()
{
    // tạo lá;
    for (int i = 0; i < n; i++)
        // xử lý thêm mối nút có được x2 không
        tree[k][p + i] = isDouble(i + 1, k)
                             ? (2 * a[i])
                             : a[i];
    // tạo các nút còn lại
    for (int i = p - 1; i > 0; i--)
        tree[k][i] = tree[k][2 * i] + tree[k][2 * i + 1];
}
void update(int i, int64_t val)
{
    int u = i + p - 1;
    tree[k][u] = isDouble(i, k) ? 2 * val : val;
    while (u > 1)
    {
        u >>= 1;
        tree[k][u] = tree[k][u * 2] + tree[k][u * 2 + 1];
    }
}
int64_t query(int L, int R)
{
    int u = L + p - 1;
    int v = R + p - 1;
    int64_t sum = 0;
    while (u <= v)
    {
        if (u % 2 == 1)
            sum += tree[k][u++];
        if (v % 2 == 0)
            sum += tree[k][v--];
        u >>= 1;
        v >>= 1;
    }
    return sum;
}
// void printVector(vector<int> x)
// {
//     for (auto i : x)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
// }
int main()
{
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);
    int q;
    cin >> n >> q;
    a.resize(n);
    for (int &i : a)
        cin >> i;
    // tạo cây segment tree; n<2^5; và 1<=k<=9
    // khai báo, tạo lá, tạo cây
    p = 1;
    while (p < n)
        p <<= 1;
    for (k = 1; k <= 9; k++)
    {
        // tạo 9 cây segment tree để sử lý từng k
        tree[k].resize(4 * p);
        buildTree();
    }
    // sử lý từng truy vấn q
    while (q--)
    {
        int t;
        p = 1;
        while (p < n)
            p <<= 1;
        cin >> t;
        // nếu 1: update 9 segment tree
        if (t == 1)
        {
            int i, c;
            cin >> i >> c;
            for (k = 1; k <= 9; k++)
                update(i, c);
        }
        // nếu 2: query sum l-r;
        else if (t == 2)
        {
            int L, R;
            cin >> L >> R >> k;
            cout << query(L, R) << endl;
        }
    }
    return 0;
}