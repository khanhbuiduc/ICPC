
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int f[5005][5005];
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "0" + s;
    // btsc
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    // ct hồi quy
    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (s[i] == s[j])
                f[i][j] = f[i + 1][j - 1];
            else
            {
                f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
            }
        }
    }
    // đáp án:

    cout << f[1][n];
}
/*
    gọi f[i][j] là số lượng ký tự thêm vào tối thiểu để chuỗi thành Palindrome

    bài toán cơ sở: f[i][i]=0 với i:1->n

    đáp án: f[1][n]

    công thức hổi quy:

    case1: s[i]=s[j] thì f[i][j] = f[i+1][j-1];
    case2: s[i]!=s[j]: f[i][j] = min(f[i+1][j] +1, f[i][j-1]+1)

    for i:n->1
        for j:i+1->n;
            case1...
            case2....

*/