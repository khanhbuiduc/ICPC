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

cho dãy P357:
    - là số tự nhiên < N với N< 1 tỉ
    - Ngoại trừ phần tử A đầu tiên, phần tử của dãy luôn tìm thấy ít nhất một phần tử B đứng trước nó mà A-1 chia cho B được thương số là 3,5,7
        => A = 3*B + 1 hoặc A = 5*B + 1 hoặc A = 7*B + 1
    - Phần tử đầu tiên của dãy là 1
Yêu cầu:
    - Đếm số lượng phần tử của dãy.

cách làm:
- sử dụng set để lưu các phần tử của dãy
- thêm phần tử 1 vào set
- sử dụng queue để duyệt các phần tử của dãy
- trong khi queue không rỗng thì lấy phần tử đầu tiên ra

*/
