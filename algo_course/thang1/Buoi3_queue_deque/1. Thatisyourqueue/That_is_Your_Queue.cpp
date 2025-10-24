#include <bits/stdc++.h>
using namespace std;
int main()
{
    int P, C, x;
    char c;
    int T = 0;
    while (++T)
    {
        cin >> P >> C;
        if (P == 0 && C == 0)
            return 0;
        cout << "Case " << T << ":\n";
        queue<int> q1;
        queue<int> q2;
        for (int i = 1; i <= min(P, C); i++)
        {
            q1.push(i);
        }
        while (C--)
        {
            cin >> c;
            if (c == 'N')
            {
                cout << q1.front() << "\n";
                q1.push(q1.front());
                q1.pop();
            }
            else if (c == 'E')
            {
                cin >> x;
                q2.push(x);
                while (!q1.empty())
                {
                    if (q1.front() != x)
                        q2.push(q1.front());
                    q1.pop();
                }
                swap(q1, q2);
            }
        }
    }
}
/*
 có P bệnh nhân được đánh số từ 1->P;và có C lần sử lý người xếp trc được gọi trc. khi gọi xong lại xếp xuống cuối hàng.
    3 6
    N 1
    N 2
    E 1
    N 1
    N 3
    N 2
    [1 2 3]->[2 3 1]->[3 1 2]->[1 3 2]->[3 2 1]->[2 1 3]->[1 3 2]

    queue chỉ chứa 1->min(P,C);// cho chỉ có C truy vấn
    nếu là N: in ra và đẩy giá chị front xuống cuối.
    nếu là E x:
        - q2: thêm x vào đầu
        - lấy từng giá trị q1 cho vào q2
            - nếu số đó=x thì bỏ qua



*/