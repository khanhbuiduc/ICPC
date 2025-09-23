#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int main()
{
}
/*
f(0) = 0
f(1) = 1
f(2) = 2
f(3k) = f(2k)
f(3k+1) = f(2k) + f(2k+1)
f(3k+2) = f(2k) + f(2k+1) + f(2k+2)

cách làm:
- sử dụng đệ quy có ghi nhớ
- nếu n = 0 hoặc n = 1 hoặc n = 2 thì trả về n
- nếu f(n) đã được tính thì trả về f(n)
- nếu n chia hết cho 3 thì f(n) = f(2*n/3)
- nếu n chia 3 dư 1 thì f(n) = f(2*n/3) + f(2*n/3 + 1)
- nếu n chia 3 dư 2 thì f(n) = f(2*n/3) + f(2*n/3 + 1) + f(2*n/3 + 2)
- in ra kết quả
*/