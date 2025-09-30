#include <bits/stdc++.h>
using namespace std;
map<char, int> precedence{{'+', 1}, {'-', 1}, {'/', 2}, {'*', 2}, {'^', 3}};
int main()
{
    stack<char> st;
    int t;
    cin >> t;
    string expression;
    while (t--)
    {
        cin >> expression;
        for (auto c : expression)
        {
            if (isalpha(c))
                cout << c;
            else if (c == '(')
                st.push('(');
            else if (c == ')')
            {
                while (st.top() != '(')
                {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && precedence[c] <= precedence[st.top()])
                {
                    cout << st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << "\n";
    }
    return 0;
}
/*
    (a+(b*c))->abc*+
    xét từng hàm:
    if(c):
     anphabet: in ra luôn
     "(": đẩy vào stack
     ")":lấy dấu trong stack đến khi gặp "("
     "phép toán": xét độ ưu tiên: độ ưu tiên cao hơn ra trc, rồi mới đẩy toán tử hiện tại vào stack.
    - lần lượt đẩy các toán tử còn lại từ stack vào tiền tố
*/