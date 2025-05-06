/*
    Author : buiduckhanh
    Problem Name : PON - Prime or Not ( SPOJ )
    ALGORITHM : Number Theory
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* Calculate ( a*b ) %c */
ll mulmod(ll a, ll b, ll c)
{ // a*1001=
    return (__int128)a * b % c;
}

/* Calculate ( a^b ) %c */
ll powmod(ll a, ll b, ll c)
{
    ll x = 1, y = a % c;
    while (b > 0)
    {
        if (b % 2)
            x = mulmod(x, y, c);
        y = mulmod(y, y, c);
        b /= 2;
    }
    return x % c;
}
bool test(long long a, long long n, long long k, long long m)
{
    // x= a ^ m % n
    long long x = powmod(a, m, n);
    // nếu a^m = 1 mod n thì n là số nguyên tố
    if (x == 1 || x == n - 1)
        return true;
    // nếu bình phương x trở thành n - 1 thì n là số nguyên tố
    for (int i = 1; i < k; i++)
    {
        // x=(a^(2^i*m)) = -1 mod n thì n là số nguyên tố
        x = mulmod(x, x, n);
        if (x == n - 1)
            return true;
    }
    return false;
}
bool miller_rabin(long long n)
{
    static vector<int> checkSet = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (auto a : checkSet)
        if (n == a)
            return true;
    if (n < 41)
        return false;

    long long k = 0, m = n - 1;
    // Viết n - 1 dưới dạng m * 2^k với m lẻ
    while (m % 2 == 0)
    {
        m /= 2;
        k++;
    }
    // kiểm tra xem có phải hợp số không
    for (auto a : checkSet)
        if (!test(a, n, k, m))
            return false;
    return true;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;

        if (miller_rabin(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}