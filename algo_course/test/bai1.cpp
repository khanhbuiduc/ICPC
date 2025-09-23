#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans++;
            if (i * i != n)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
/*
cho n <= 2 tỉ.
đếm số lượng ước số của n.
Yêu cầu O(sqrt(n))
cách làm:
- duyệt i từ 1 đến sqrt(n)
- nếu i chia hết cho n thì i là 1 ước số
- nếu i*i khác n thì n/i cũng là 1 ước số
- in ra kết quả
*/