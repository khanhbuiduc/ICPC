#include <bits/stdc++.h>
using namespace std;
map<char, int> ptk{{'C', 12}, {'O', 16}, {'H', 1}};
map<char, int> precedence{{'+', 1}, {'*', 2}};
int T;
string cthh = "", infix = "", postfix = "";

void CTHHtoInfix()
{
    for (auto c : cthh)
    {
        if (isalpha(c) || c == '(')
        {
            if (infix.size() && infix.back() != '(')
                infix += '+';
        }
        else if (isdigit(c))
        {
            infix += '*';
        }
        infix += c;
    }
}

void infixToPostfix()
{
    stack<int> st;
    for (auto c : infix)
    {
        if (isalpha(c) || isdigit(c))
            postfix += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            if (!st.empty() && precedence[st.top()] >= precedence[c])
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
}
int operation(int a, int b, int o)
{
    return o == '+' ? a + b : a * b;
}
int evalPostfix()
{
    stack<int> st;
    int a, b;
    int eval = 0;
    for (auto c : postfix)
    {
        if (isalpha(c))
        {
            st.push(ptk[c]);
        }
        else if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(operation(a, b, c));
        }
    }
    return st.top();
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> cthh;
        CTHHtoInfix();
        // cout << infix;
        infixToPostfix();
        // cout << postfix;
        cout << evalPostfix();
        infix.clear();
        postfix.clear();
        cout << "\n";
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