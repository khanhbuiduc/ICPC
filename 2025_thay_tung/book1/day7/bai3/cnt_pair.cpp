#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int x, l, r;
    cin >> x >> l >> r;

    FOR(i, l, r)
    {
        int g = gcd(i, x);
        if (g == 1 || isPrime(g))
        {
            cout << i << ' ';
        }
    }
}
/*
đếm có bao nhiêu cặp không cùng mạch.
cùng k cùng mach: có tối đa 1 ước chung khác 1.
=>gcd(a,b) = 1, gcd(a,b) là snt;
---

*/