#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, i = 1, ki, w, h;
    ll maxAD = 0;
    cin >> n;
    stack<pii> st;
    st.push({-1, 0}); //{hight,index}
    while (i <= n + 1)
    {
        if (i < n + 1)
            cin >> ki;
        else
            ki = 0;
        while (ki <= st.top().ff)
        {
            auto top = st.top();
            st.pop();
            w = i - st.top().ss - 1;
            h = top.ff;
            ll area = 1ll * w * h;
            maxAD = max(maxAD, area);
        }
        st.push({ki, i});
        i++;
    }
    cout << maxAD;
}
/*
- cách 1:
     sử dụng 2 stack giống như bài nearest_smaller_values để tìm giá trị nhỏ gần nhất trái prevS[i] và giá trị nhỏ gần nhất phải nextS[i].
     width = nextS[i] – prevS[i] – 1
     area=arr[i] * width
- cách 2: // https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-stack/
stack:
    thêm đầu và cuối stack là số 0;
    vị trí hiện tại cur <= vị trí trc đó top:
        tính diện tính của phần trc đó
        wight= cur-top-1
        hight= chiều cao của top
*/