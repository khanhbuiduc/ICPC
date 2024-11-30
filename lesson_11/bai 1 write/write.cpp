#include <bits/stdc++.h>
using namespace std;
vector<int> result;
typedef pair<int, int> pii;

int main()
{
    freopen("write.inp", "r", stdin);
    freopen("write.out", "w", stdout);
    string s, ans = "";
    cin >> s;
    // tính địa chỉ đầu của các nút trong cây
    int n = s.size();
    int p = 1;
    while (p < n)
        p <<= 1;
    vector<pii> t(4 * n + 10, {123, 1});
    stack<int> st;
    // tìm và xử lý kí tự min tỏng xâu
    char ch = *min_element(s.begin(), s.end());
    // ký tự cuối cùng không phải là ch
    if (s[n - 1] != ch)
        st.push(n - 1);
    // tìm và xử lý kí tự min
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == ch)
        {
            ans += ch;
            s[i] = '{';
            st.push(i);
            if (i > 0)
                st.push(i - 1);
        }
        else
            t[p + i] = {s[i] - 97, -i};
    }
    // xây dựng segment tree;
    for (int i = p - 1; i > 0; --i)
        t[i] = min(t[2 * i], t[2 * i + 1]);
    // cập nhập khi kí tự ở vị trí x được chọn
    auto upd_t = [&](int x)
    {
        int v = p + x;
        t[v] = {123, 1};
        while (v > 1)
        {
            v >>= 1;
            t[v] = min(t[2 * v], t[2 * v + 1]);
        }
    };
    // tìm ký tự min xâu con kết thúc ở vị trí x
    auto get_min = [&](int x)
    {
        int v = p + x;
        pii r = t[v];
        while (v > 0)
        {
            if (v & (-v) == v)
                break;
            if (v & 1)
                r = min(r, t[v - 1]);
            v >>= 1;
        }
        return r;
    };
    pii res;
    while (!st.empty())
    {
        int q = st.top();
        res = get_min(q);
        auto [u, v] = res;
        v = -v;
        if (u > 26)
        {
            st.pop();
            continue;
        }
        s[v] = '{';
        upd_t(v);
        ans += char(u + 97);
        st.push(v);
        if (v > 0)
            st.push(v - 1);
    }
    cout << ans;
}

/*sâu s độ dài n:
chọn kí tự si
tách s thành 2 xâu sl=s[1...i-1]; sr=s[i+1...sn]
thực hiện hiện với xâu s1 và sau đó với xâu sr
output: thứ tự từ điển nhỏ nhất  theo giải thuật trên


*/