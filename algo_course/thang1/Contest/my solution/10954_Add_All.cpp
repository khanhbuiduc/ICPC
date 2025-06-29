#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int N;
    while (cin >> N && N)
    {
        priority_queue<int, vector<int>, greater<int>> s;
        ll res = 0;
        int ai;
        for (int i = 0; i < N; i++)
        {
            cin >> ai;
            s.push(ai);
        }
        // lấy 2 min và tính tổng đổng thời update chi phí
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            int sum = a + b;
            res += sum;
            s.push(sum);
        }
        cout << res << "\n";
    }
}
/*
    1 3 5 7 8;
    nhận thấy cách tối ưu nhất là cộng 2 số nhỏ nhất:
    1+4=4;
    4 5 7 8
    4+5=9;
    9 7 8
    7+8=15;
    9 15
    15+9=24
    24;
    hết
    dùng priority_query để lấy 2 min;

*/