#include <bits/stdc++.h>
using namespace std;

int n, p;
vector<int> a;
vector<int> minTree, maxTree;

void buildMinMaxTree()
{
    // Xác định kích thước cây
    p = 1;
    while (p < (n + 1) / 2)
        p <<= 1;

    minTree.assign(4 * p, INT_MAX);
    maxTree.assign(4 * p, INT_MIN);

    // Khởi tạo các cặp tối ưu ban đầu: 0->(n-1), 1->(n-2), ...
    for (int i = 0; i < n / 2; i++)
    {
        int sum = a[i] + a[n - 1 - i];
        minTree[p + i] = sum;
        maxTree[p + i] = sum;
    }
    // Build tree từ dưới lên
    for (int i = p - 1; i > 0; i--)
    {
        minTree[i] = min(minTree[2 * i], minTree[2 * i + 1]);
        maxTree[i] = max(maxTree[2 * i], maxTree[2 * i + 1]);
    }
}

void update(int pos, int newSum)
{
    int u = p + pos;
    minTree[u] = newSum;
    maxTree[u] = newSum;

    while (u > 1)
    {
        u >>= 1;
        minTree[u] = min(minTree[2 * u], minTree[2 * u + 1]);
        maxTree[u] = max(maxTree[2 * u], maxTree[2 * u + 1]);
    }
}

pair<int, int> getMinMax()
{
    return {minTree[1], maxTree[1]};
}
void initial()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    buildMinMaxTree();
}
int main()
{
    initial();

    int result = INT_MAX;
    // ban đầu manager là a[0]
    auto [minVal, maxVal] = getMinMax();
    result = min(result, maxVal - minVal);
    // Thử từng manager khác
    for (int manager = 1; manager < n; manager++)
    {
        // manager thay đổi tổng ở cặp thứ mấy.
        int affectedPair = (manager <= n / 2 ? manager - 1 : n - manager - 1);
        int i = manager - 1;
        // Tính tổng mới cho cặp bị ảnh hưởng
        int newSum = a[i] + a[n - 1 - i];

        // Cập nhật segment tree
        update(affectedPair, newSum);

        auto [minVal, maxVal] = getMinMax();
        result = min(result, maxVal - minVal);
    }

    cout << result << endl;
    return 0;
}