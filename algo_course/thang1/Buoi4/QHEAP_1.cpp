#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> nums;
    int Q, type, num;
    cin >> Q;
    while (Q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> num;
            // insert num;
            if (!nums.count(num))
            {
                nums.insert(num);
                pq.push(num);
            }
        }
        else if (type == 2)
        {
            cin >> num;
            // remove num;
            nums.erase(num);
        }
        else if (type == 3)
        {
            while (!nums.count(pq.top()))
                pq.pop();
            // print
            cout << pq.top() << "\n";
        }
    }
}
/*
    đề bài: có Q truy vấn: gồm 3 loại: thêm, xóa, in ra min của heap
    ngây thơ:
        - dùng thêm 1 priority_queue:
            - khi thêm hoặc xóa: chuyển lần lượt từ pq1 sang pq2 và gặp num thì xóa.
                - thêm: khi xóa xong thì thêm lại num để chánh bị lặp
    // cách dùng thêm 1 set hoặc dùng priority_queue
        khi xóa thì thêm vào cả pq1 và pq2:(trùng không ảnh hưởng)
            - khi tìm min: nếu min của pq2=min của pq1 thì xóa min của cả 2 đi. đến khi min của pq1!= min pq2
    vd:
    Q = 20
        1 5         H = {5}, Q2 = (}
        1 8         H = {5, 8}, Q2 = (}
        1 4         H = {5, 8, 4}, Q2 = {}
        2 5         H = {5, 8, 4}, Q2 = {5}
        3           --- > 4
        1 10        H = {5, 8, 4, 10}, Q2 = {5}
        2 8         H = {5, 8, 4, 10}, Q2 = {5, 8}
        2 4         H = {5, 8, 4, 10}, Q2 = {5, 8, 4}
        3           -- > 10         , H = {10}, Q2 = {}
        1 2         ...
        1 2
        1 10
        3
        2 10
        3
        2 2
        2 2
        19
        11
        3

    */
