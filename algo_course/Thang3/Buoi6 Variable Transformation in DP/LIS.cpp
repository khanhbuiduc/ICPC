#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
ll f[30'005]; // chỉ số phần tử, với len
int a[30'005];
int binary_search(int l, int r, int x)
{
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[f[mid - 1]] < x)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -INF;
    f[0] = 0;
    int maxlength = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[f[maxlength]])
        {
            maxlength++;
            f[maxlength] = i;
        }
        else
        {
            int len = binary_search(1, maxlength, a[i]);
            if (a[f[len]] > a[i])
            {
                f[len] = i;
            }
        }
    }
    cout << maxlength;
}
/*
Cho một dãy gồm số nguyên Hãy tìm dãy con tăng dài nhất trong dãy đó. In ra số lượng phần tử của dãy con. Các số trong phạm vi longint.
n = 5
5 1 9 2 4 3 6 7 7 8 10 2 12
output
3

i = 5
    F[1] = 2
    F[2] = 4
    F[3] = 5

i = 6; a[i] = 3
    f[1] = 2
    f[2] = 4;  thấy f[2] có số cuối = 2 => a[f[3]] > 3; update f[3]'
    f[3] = 6

i = 7; a[i] = 6
    f[1] = 2;
    f[2] = 4;
    f[3] = 6; a[f[3]] = 3 < 6; cập nhập f[4] = i (a[f[maxleng]] luôn lớn nhất nên k cần cập nhập)
    f[4] = 7;
---------------


cách đúng:
    - với phần tử i gọi f[len]: 1->maxlength là chỉ số của phần tử có giá trị nhỏ nhất trong tất cả các dãy con tăng có độ dài là len
bài toán cơ sở:
    f[0] = 0
    maxlength = 0
đáp án: maxlength

QHD:
    xét phần tử i:
    case 1: a[i] là một số làm cho dãy có độ dài tăng lên (a[F[maxlength]] < a[i])
        maxlength++;
        f[maxlength] = i;
    case 2: a[i] là 1 số không làm cho dãy có độ dài tăng lên
        xét a[i] có thể là số cuối cùng của dãy có leng lớn nhất bao nhiêu:
            tìm: BS: a[F[len]] < a[i] với leng lớn nhất
            kiểm tra xem nếu: a[f[len]] > a[i]
                f[len] = i;
*/