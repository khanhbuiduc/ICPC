#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> store;

long long f(long long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (store.count(n))
        return store[n];

    long long res;
    long long k = n / 3;
    if (n % 3 == 0)
        store[3 * k] = f(2 * k);
    else if (n % 3 == 1)
        store[3 * k + 1] = f(2 * k) + f(2 * k + 1);
    else
        store[3 * k + 2] = f(2 * k) + f(2 * k + 1) + f(2 * k + 2);
    return store[n];
}

int main()
{
    long long n;
    cin >> n;
    cout << "Nhap n = " << "\n";
    cout << "f(" << n << ") = " << f(n) << "\n";
    return 0;
}

/*
đề bài:
f(0) = 0
f(1) = 1
f(2) = 2
f(3k) = f(2k)
f(3k+1) = f(2k) + f(2k+1)
f(3k+2) = f(2k) +f(2k+1) + f(2k+2)
---------------------------------

cách ngây thơ: dùng quy hoạch động:

btcs: f(0) = 0; f(1) = 1; f(2) = 2;

đáp án: f(n)

QHD: xét i:3->n
    k = i / 3
    nếu i%3==0: f(3k) = f(2k)
    nếu i%3==1: f(3k+1) = f(2k) + f(2k+1)
    nếu i%3==2: f(3k+2) = f(2k) + f(2k+1) + f(2k+2)

bài toán này bị phá sản do n < 2 * 10^9

--------
nhận xét
    - chỉ cần tính O(n)
    - số f(n) liên quan đến f(2/3*n)
(1 / 1.5)^100 ~= 2.45*10^(-18)

với bất kì n < 2 * 10^9 ta có:
    n * (1 / 1.5)^100 <= 10^(-8) ~= 0
...
trường hợp tệ nhất. mỗi lần n%3 dư 2: thì cần (100)^3 = 1'000'000

-------------------------------------------
dùng đệ quy:f(n)

btcs: f(0) = 0; f(1) = 1; f(2) = 2; f(n) = store[n]// nếu đã tính.

đáp án: f(n)

đệ quy:
    k = i / 3
    nếu i%3==0: f(n) = f(2k)
    nếu i%3==1: f(n) = f(2k) + f(2k+1)
    nếu i%3==2: f(n) = f(2k) + f(2k+1) + f(2k+2)
    lưu f(n);

----- lưu trữ
chỉ tính các số cần thiết: lưu trữ trong store
    - lấy có n: lấy f(n): O(n)< căn n
    - thêm 1 số vào: O(n)< căn n
    => dùng unorder_map: O(1) thêm, lấy.
-----



*/