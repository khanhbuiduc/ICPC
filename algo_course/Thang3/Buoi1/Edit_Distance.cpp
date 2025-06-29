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
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();
    // bài toán cơ sở
    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int i = 0; i <= m; i++)
        f[0][i] = i;
    // hồi quy
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                f[i][j] = f[i - 1][j - 1];
            else
            {
                f[i][j] = min(f[i][j - 1] + 1, min(f[i - 1][j] + 1, f[i - 1][j - 1] + 1));
            }
        }
    }
    // đáp án
    cout << f[n][m];
}
// f[i][j] số cách biến đổi nhỏ nhất biến i kí tự str1 thành j kí tự str2

/*
bài toán cơ sở: f[i][0] = i; f[0][j]=j;
đáp án: f[n][m];

TH1: str1[i] = str2[j] thì f[i][j] = f[i-1][j-1]
TH2: str1[i] != str2[j]:
    biến đổi i kí tự str1 thành j-1 kí tự str2 rồi insert: f[i][j] = f[i][j-1] +1
    biến đổi i - 1 kí tự str1 thành j kí tự str2 rồi insert: f[i][j] = f[i - 1][j] +1
    biến đổi i - 1 kí tự str1 thành j - 1 kí tự str2 rồi replace: f[i][j] = f[i - 1][j -1] +1

    =====> f[i][j] = min (f[i][j-1] +1, f[i - 1][j] +1, f[i - 1][j -1] +1);
*/