#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    int xi, i = 1;
    stack<pii> st;
    st.push({0, 0});
    while (i <= n)
    {
        cin >> xi;
        while (st.top().ff >= xi)
            st.pop();
        cout << st.top().ss << ' ';
        st.push({xi, i});
        i++;
    }
}
// stack lưu vị trí gần nhất tiềm năng
// 2 5 1 4 8 3 2 5
// số nhỏ hơn số bên trái không có ý nghĩa
// sét 1: stack{2,5}-> thì stack{1};