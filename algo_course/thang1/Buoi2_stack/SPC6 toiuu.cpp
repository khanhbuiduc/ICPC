#include <bits/stdc++.h>
using namespace std;
map<char, int> ptk{{'C', 12}, {'O', 16}, {'H', 1}};
int T;
string expression;
int main()
{
    cin >> T;
    stack<int> st;

    while (T--)
    {
        cin >> expression;
        for (auto c : expression)
        {
            if (isalpha(c))
                st.push(ptk[c]);
            else if (isdigit(c))
            {
                int top = st.top();
                st.pop();
                st.push(top * (c - '0'));
            }
            else if (c == '(')
                st.push(0);
            else if (c == ')')
            {
                int sum = 0;
                while (st.top())
                {
                    sum += st.top();
                    st.pop();
                }
                st.pop(); // bỏ dấu '('
                st.push(sum);
            }
        }
        int result = 0;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        cout << result << '\n';
    }
}

/*
    cách 1:
    b1: chuyển từ tiền tố sang hậu tố: giống bài Transform the Expression
        1.1 chuyển từ công thức hóa học sang biểu thức tiền tố:
            if: chữ hoặc (:
                đằng trc khác rỗng hoặc ( thì thêm '+' vào
            if: ): giữ nguyên;
            if: số thì thêm * đằng trc

        1.2 chuyển từ tiền số sang chuỗi hậu tố:
            - nếu là chữ hoặc số:
                - thêm vào stack (dạng số);
            - nếu là (: thêm vào stackpost;
            - nếu là ): thêm các phép toán vào chuỗi hậu tố đến khi gặp (
            - nếu là phép toán: nếu độ ưu tiên nhỏ hơn trong stack thì lấy phép toán trong stack ra
            - khi hết thì lấy các phép toán còn lại ra.
    b2: tính toán  hậu - tố xét từng kí tự:
        - nếu là số: thêm vào stack;
        - nếu là phép toán (o):
            lấy ra 2 số a,b trong stack
            tính res=a o b
            thêm res vào stack
        - khi không còn kí tự nào thì kết quả sẽ là số còn lại trong stack
    cách 2:
    tính trực tiếp từ tiền tố:
    - duyệt từng ký tự
        - if: chữ sẽ thêm vào stack;
        - if số: nhân với top của stack
        - if (: thêm 0 vào stack
        - if ): cộng lại đến khi bằng 0;
    - nếu đã duyệt hết: tính tổng và in ra;

    C(COOH)2
    12,
    12,0
    12,0,12,16,16,1



*/