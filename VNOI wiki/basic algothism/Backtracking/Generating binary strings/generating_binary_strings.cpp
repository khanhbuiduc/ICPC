#include <bits/stdc++.h>
using namespace std;

#define MOD 1'000'000'007
int n;
string curString = "";
typedef pair<int, string> pis;
void genString(int pos)
{
    if (pos > n)
    {
        cout << curString << endl;
        return;
    }
    for (int i = '0'; i <= '1'; i++)
    {
        curString.push_back(i);
        genString(pos + 1);
        curString.pop_back();
    }
}
void genStringStack()
{
    stack<pis> st;
    st.push({0, ""});
    while (!st.empty())
    {
        auto [pos, curStr] = st.top();
        st.pop();
        if (pos == n)
        {
            cout << curStr << endl;
            continue;
        }
        st.push({pos + 1, curStr + "1"});
        st.push({pos + 1, curStr + "0"});
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    // genString(1);
    genStringStack();
    return 0;
}
