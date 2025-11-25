#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
int n;
int a[200'005];
vector<int> NSV()
{
    vector<int> res(n + 1);
    stack<int> st;

    FOR(i, 1, n)
    {
        // Xóa các phần tử >= a[i]
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        res[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    return res;
}

int main()
{
    cin >> n;
    FOR(i, 1, n) { cin >> a[i]; }
    vector<int> nearestSV = NSV();
    for (auto i : nearestSV)
        cout << i << ' ';
}
// stack lưu vị trí gần nhất tiềm năng
// 2 5 1 4 8 3 2 5
// số nhỏ hơn số bên trái không có ý nghĩa
// sét 1: stack{2,5}-> thì stack{1};