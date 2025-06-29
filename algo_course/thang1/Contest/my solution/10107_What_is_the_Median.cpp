#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
priority_queue<int> queue1;
priority_queue<int, vector<int>, greater<int>> queue2;
void balance()
{
    if (queue1.size() >= queue2.size() + 2)
    {
        queue2.push(queue1.top());
        queue1.pop();
    }
    if (queue1.size() + 1 <= queue2.size())
    {
        queue1.push(queue2.top());
        queue2.pop();
    }
}
int main()
{
    int x;
    int count = 0;

    while (cin >> x)
    {
        count++;
        if (queue1.empty() || x < queue1.top())
            queue1.push(x);
        else
            queue2.push(x);
        balance();
        if (count & 1)
            cout << queue1.top() << "\n";
        else
            cout << (queue1.top() + queue2.top()) / 2 << "\n";
    }
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}
/*
    bài này cần dùng 2 hàng đợi ưu tiên để mỗi khi thêm 1 phần tử vào đều đã đc sắp sếp dễ dàng lấy trung bình.
    queue1 là heap max; queue là heap min
    - queue1.size() = queue2.size() (hoặc queue2.size()+1)
    - thêm lần lượt phần tử x vào:
        nếu x< max queue1 thêm vào queue1;
        nếu không thêm vào queue2;
        cân bằng lại queue;
            queue1   >= queue2+2// chuyển top queue1 sang queue2
            queue1 +1<= queue2// chuyển top queue2 sang queue1


*/