#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
bool is_prime[maxn];
void eratosthenes(int n)
{
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b;
    cin >> a >> b;
    eratosthenes(b);
    for (int i = a; i <= b; i++)
        if (is_prime[i])
            cout << i << "\n";
    return 0;
}