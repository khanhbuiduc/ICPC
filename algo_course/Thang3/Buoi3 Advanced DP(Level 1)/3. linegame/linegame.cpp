#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
ll f[1'000'005][2]; // 10^6 * 5*10^3 = 5*10^9
int a[1'000'005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = -1e9;
        f[i][1] = -1e9;
    }
    f[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int state = 0; state <= 1; state++)
        {
            f[i + 1][state] = max(f[i + 1][state], f[i][state]);
            f[i + 1][1 - state] = max(f[i + 1][1 - state], f[i][state] + (state ? -1 : 1) * a[i + 1]);
        }
    }
    cout << max(f[n][0], f[n][1]);
}
/*
    Gọi f[i][state] là tổng giá trị lớn nhất khi có i phần tử, phân tử TIẾP THEO mà ta muốn mang dấu sẽ có trạng thái là state
        state = 0: phần tử TIẾP THEO mang dầu dương
        state = 1: phần tử TIẾP THEO mang dấu âm
    bài toán cơ sở:
        f[0][0] = 0;
        f[i][j] = - inf;
    đáp án bài toán:
        Max(f[n][0], f[n][1])
    công thức quy hoạch động: (f[i][state] != inf)

    Nếu chấp nhận a[i+1]
        Nếu state = 0;
            f[i+1][1] = max(f[i+1][1], f[i][state] + a[i+1])
        Nếu state = 1:
            f[i+1][0] = max(f[i+1][0], f[i][state] - a[i+1]);
        ==>f[i+1][1-state] = max(f[i+1][1-state], f[i][state] +(state?-1:1)*a[i])
    Nếu không chấp nhận a[i+1]:
        f[i+1][state] = max(f[i+1][state], f[i][state]);
    khônng tính đc do nếu k dùng số đó thì k tính đc
    -------------------------------------------


*/