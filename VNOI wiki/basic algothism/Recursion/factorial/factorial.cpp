#include <bits/stdc++.h>
using namespace std;

#define MOD 1'000'000'007

// Tính giai thừa có modulo để tránh tràn số
long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result = (result * i) % MOD;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}
