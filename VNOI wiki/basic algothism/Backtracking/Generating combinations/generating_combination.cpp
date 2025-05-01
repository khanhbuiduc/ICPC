#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
vector<int> arr;
vector<string> listBinary;
int n;
string curString = "";
typedef pair<int, string> pis;

void gencombination()
{
    stack<pis> st;
    st.push({0, ""});
    while (!st.empty())
    {
        auto [pos, curStr] = st.top();
        st.pop();
        if (pos == n)
        {
            if (!curStr.empty())
                cout << curStr << endl;
            continue;
        }
        st.push({pos + 1, curStr + (curStr.empty() ? "" : " ") + to_string(arr[pos])});
        st.push({pos + 1, curStr});
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    arr.resize(n);
    for (int &i : arr)
        cin >> i;
    // genString(1);
    gencombination();
    return 0;
}
