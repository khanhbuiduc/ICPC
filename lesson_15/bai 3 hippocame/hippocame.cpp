#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hippocame.inp", "r", stdin);
    freopen("hippocame.out", "w", stdout);
    //=====nhập dữ liệu=======
    int n;
    cin >> n;
    vector<int> p(n, 0);
    for (int i = 1; i < n - 1; i++)
    {
        cin >> p[i];
    }
    cout << "p= {";
    for (int i : p)
        cout << i << " ";
    cout << "}" << endl;
    // tạo bảng go[i] xác định vị trí cuối cùng của quân mã nếu đi vào ô i
    vector<int> go(n);
    for (int i = 0; i < n; i++)
        if (p[i] == 0)
            go[i] = i;
        else
            go[i] = go[i - p[i]];
    const int inf = (int)1e9;
    cout << "go= {";
    for (int i : go)
        cout
            << i << " ";
    cout << "}" << endl;
    // số nước ngắn nhất đi đến từng cị trí;
    vector<int> d(n, inf);
    d[0] = 0;
    deque<int> q;
    q.push_back(0);
    while (!q.empty())
    {
        int i = q.front();
        q.pop_front();

        for (int x = 1; x <= 6; x++)
        {
            if (i + x >= n)
                continue;
            int to = go[i + x];
            int nd = d[i] + (x < 6 || to == (n - 1));
            if (nd < d[to])
            {
                d[to] = nd;
                if (nd == d[i])
                    q.push_front(to);
                else
                    q.push_back(to);
            }
        }
    }
    cout << "num of step: ";
    if (d[n - 1] == inf)
        cout << "-1" << endl;
    else
        cout << d[n - 1] << endl;
}
//
/*
    tạo bảng go[i] xác định vị trí cuối cùng của quân mã nếu đi vào ô i
    điểm cuối của chuỗi lùi trái từ mỗi vị trí
        ô có giá trị 0: ở nguyên vị trí
        ô có giá trị val: lùi lại val vị trí
    số nước ngắn nhất đi đến từng vị trí
         ô đầu tiên cần 0 bước;
        lưu vị trí 0 vào stack
        duyệt stack;
            lấy phần tử đầu; ta có vị trí hiện tại
            từ phần tử đó ta có 0<x<7 cách đi;
            mỗi cách ta sẽ tính
                - tới ô nào = go[i+x]
                - số nước đi=(d[hiện tại])+1 nếu x< 6 hoặc đã đến ô cuối
            nếu số nước đi ở ô đó < số nước đi ở ô đó
                - cập nhập số nước đi
                - nếu đi 6 nước thêm vị trí vào đầu stack
                - nếu không thêm vào cuối stack
    nếu d cuối = inf thì in -1;
    nếu không thì in d cuối
*/