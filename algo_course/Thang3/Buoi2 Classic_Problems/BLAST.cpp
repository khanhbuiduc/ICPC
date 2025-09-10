
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int f[2005][2005];
int main()
{
    string a, b;
    int k;
    cin >> a >> b >> k;
    int m = a.length(), n = b.length();
    a = " " + a;
    b = " " + b;
    for (int i = 1; i <= m; i++)
        f[i][0] = k * i;
    for (int j = 1; j <= n; j++)
        f[0][j] = k * j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = min(f[i][j - 1] + k, min(f[i - 1][j] + k, f[i - 1][j - 1] + abs(a[i] - b[j])));
        }
    }
    cout << f[m][n];
}

/*
K<100
a,b<2000
input:
    a=cmc
    b=snmn
    k=2
gọi f[i][j] là tổng chi phí tối thiểu khi ta có i kí tự dãy a và j kí tự dãy b

btcs: f[0][j] = k*j; f[i][0] = k*i;

đáp án bài toán: f[m][n] với m,n lần lượt là length của a và b

công thức qhd:
    f[i][j] = ??
    case 1: i kí tự của a thành độ dài j-1 kí tự của b rồi thêm "_" vào cuối a
        f[i][j]= f[i][j-1] + k;
    case 2: i-1 kí tự của a thành độ dài j kí tự của b rồi thêm "_" vào cuối a
        f[i][j]= f[i-1][j] + k;
    case 3: biến i-1 kí tự của a thành j-1 kí tự của b
        f[i][j]= f[i-1][j-1] + |a[i]-b[j]|;
*/