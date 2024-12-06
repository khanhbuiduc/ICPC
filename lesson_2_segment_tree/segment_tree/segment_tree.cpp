#include <bits/stdc++.h>
using namespace std;
#define NAME "segment_tree."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");

int n, p, q;
vector<int64_t> a;

void buildTree()
{
    // Xác định kích thước cây
    p = 1;
    while (p < n)
        p <<= 1;
    a.assign(4 * p, 0);
    // buildTree
    for (int i = 0; i < n; i++)
    {
        fi >> a[p + i];
    }
    for (int i = p - 1; i > 0; i--)
    {
        a[i] = a[2 * i] + a[2 * i + 1];
    }
}

void update(int i, int64_t val)
{
    int u = p + i;
    a[u] = val;
    while (u > 0)
    {
        u >>= 1;
        a[u] = a[2 * u] + a[2 * u + 1];
    }
}

int64_t sumRange(int L, int R)
{
    int64_t sum = 0;
    L += p;
    R += p;
    while (L <= R)
    {
        if (L % 2 == 1)
            sum += a[L++]; // nếu L là node phải, thêm giá trị và tiến đến node tiếp theo
        if (R % 2 == 0)
            sum += a[R--]; // nếu R là node trái, thêm giá trị và lùi về node trước
        L >>= 1;           // chuyển lên node cha
        R >>= 1;           // chuyển lên node cha
    }
    return sum;
}
int64_t sumRange(int i) // phần tử thứ i: 1,2,3...
{
    int u;
    int64_t f;
    if (i == 0)
        return 0;
    u = i + p - 1;
    f = a[u];
    while (u > 0)
    {
        if (u & 1)
            f += a[u - 1]; // nếu là lẻ: thì k có cha nữa nên cộng vào f
        u >>= 1;
    }
    return f;
}
void buildTree(int node, int start, int end)
{
    if (start == end) // Leaf node
    {
        cin >> a[node];
    }
    else
    {
        int mid = (start + end) / 2;
        int leftChild = 2 * node;
        int rightChild = 2 * node + 1;
        buildTree(leftChild, start, mid);
        buildTree(rightChild, mid + 1, end);
        a[node] = a[leftChild] + a[rightChild];
    }
}
void update(int i, int l, int r, const int &position, const int64_t &val)
{
    if (position < l || position > r)
        return;
    if (l == r)
        a[position] = val;
    int mid = (l + r) / 2;
    update(2 * i, l, mid, position, val);
    update(2 * i + 1, mid + 1, r, position, val);
    a[i] = a[2 * i] + a[2 * i + 1];
}
int64_t sumrange(int i, int L, int R, int l, int r)
{
    if (r < L || R < l)
    {
        return 0;
    }
    if (l <= L && R <= r)
    {
        return a[i];
    }
    int mid = (L + R) / 2;
    int64_t valueLeft = sumrange(2 * i, L, mid, l, r);
    int64_t valueRight = sumrange(2 * i + 1, mid + 1, r, l, r);
    return valueLeft + valueRight;
}
int main()
{
    fi >> n;
    // Xây dựng cây nhị phân tổng
    buildTree();

    // Ví dụ: tính tổng đoạn và cập nhật giá trị
    int L, R;
    fi >> L >> R;
    fo << "Tổng của đoạn [" << L << ", " << R << "] là: " << sumRange(4) << endl;

    int index;
    int64_t newVal;
    fi >> index >> newVal;
    update(index, newVal);

    fo << "Tổng của đoạn [" << L << ", " << R << "] sau cập nhật là: " << sumRange(L, R) << endl;

    return 0;
}
