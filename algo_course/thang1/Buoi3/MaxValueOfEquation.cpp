#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    int maxVal = INT32_MIN;
    deque<pair<int, int>> dq; // yi-xi,xi
    int xi, xj, yi, yj;
    for (auto point : points)
    {
        xj = point[0];
        yj = point[1];
        while (!dq.empty() && xj - dq.front().ss > k)
            dq.pop_front();
        if (!dq.empty())
            maxVal = max(maxVal, dq.front().ff + (yj + xj));
        while (!dq.empty() && (yj - xj) >= dq.back().ff)
            dq.pop_back();
        dq.emplace_back(yj - xj, xj);
    }
    return maxVal;
}
int main()
{
    freopen("output.txt", "w", stdout);
    vector<vector<int>> points = {{1, 3}, {2, 0}, {5, 10}, {6, -10}};
    int k = 1;
    cout << findMaxValueOfEquation(points, k);
}
/*
    -> yi + yj + |xi - xj|= (yi-xi)+ (yj + xj)

    dùng deque để lưu trữ {(yi-xi),xi};
        - đang xét: (xj,yj):
            1  khi xj-xi > k thì bỏ giá trị đầu deque;
            2  nếu deque không rỗng thì maxVal=max(maxVal,(yi-xi)+ (yj + xj))
                -  khi yj-xj> cuối của deque bỏ phần tử cuối đi
            3 thêm  {(yj-xj),xj} vào cuối deque
    dùng mảng ưu tiên sẽ tối ưu hơn vì không cần làm bước 2 vì  max luôn ở cuối
*/