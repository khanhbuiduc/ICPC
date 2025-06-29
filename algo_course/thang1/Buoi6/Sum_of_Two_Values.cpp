#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int n, x, ai;
    cin >> n >> x;
    map<int, int> s;
    int i = 0;
    while (++i <= n)
    {
        cin >> ai;
        if (s.find(x - ai) != s.end())
        {
            cout << s[x - ai] << " " << i;
            return 0;
        };
        s.insert({ai, i});
        }
    cout << "IMPOSSIBLE";
}

/*
    nhập ai;
    kiểm tra những số trc có số nào bằng ai không
    nếu có return kết quả luôn;

*/