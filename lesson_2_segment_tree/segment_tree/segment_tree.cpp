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
vector<int64_t> buildTree(vector<int64_t> arr)
{
    vector<int64_t> segmentTree;
    int ln = arr.size();
    int p = 1;
    while (p < ln)
        p <<= 1;
    segmentTree.assign(4 * p, 0);
    for (int i = 0; i < ln; i++)
    {
        segmentTree[p + i] = arr[i];
    }
    for (int i = p - 1; i > 0; i--)
    {
        segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
    }
    return segmentTree;
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

int main()
{
    fi >> n;
    // Xây dựng cây nhị phân tổng
    buildTree();

    // Ví dụ: tính tổng đoạn và cập nhật giá trị
    int L, R;
    fi >> L >> R;
    fo << "Tổng của đoạn [" << L << ", " << R << "] là: " << sumRange(L, R) << endl;

    int index;
    int64_t newVal;
    fi >> index >> newVal;
    update(index, newVal);

    fo << "Tổng của đoạn [" << L << ", " << R << "] sau cập nhật là: " << sumRange(L, R) << endl;

    return 0;
}
