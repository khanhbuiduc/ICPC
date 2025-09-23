#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
ll a[100'005];
ll ans = 0;
int main()
{
    int n;
    cin >> n;
    FOR(i, 0, n - 1)
    cin >> a[i];
    FOR(k, 0, n - 1)
    {
        if ((k & ~(n - 1)) == 0) // C(n-1,k)
        {
            ans ^= a[k];
        }
    }
    cout << ans;
}

/*
giải thích:
1 3 2 4 6 10
lần 1: 	1^2 + 2^3 + 3^4 + 4^5 + 5^6
lần 2:	1^(2^2)^3+  2^3^3^4  +  3^(4^4)^5 +  4^(5^5)^6
lần 3:	1^(2^2^2) ^ (3^3^3)^4 +  2^(3^3^3)^(4^4^4)^5 + 3^(4^4)^4^(5^5)^5^6
lần 4: 	1^(2^2^2^2) ^ (3^3^3^3^3^3)^(4^4^4^4)^5
----
số thứ k: C(k-1,n-1) chẵn thì bỏ qua, lẻ thì tính

dịnh lý lucas:
    a^(mod-1) đồng dư 1
C(n,k) = tích(C(ni,ki))
    - n = n0​+n1*​p+n2*​p^2+...
    - k=k0​+k1^​p+k2​*p^2+…
---
nếu C(0,1) = 0; C(1,0)=1 c(1,1) = 1, c(0,0) = 1
nếu tồn tại 1 trong ki là 0 trong ni thì C(n,k) là chẵn
=> mọi 1 trong ki là 0 trong ni thì C(n,k) là lẻ.
    => k∣n=n thì lẻ// mọi 1 trong k là 1 trong n.
    k^~n == 0
*/
