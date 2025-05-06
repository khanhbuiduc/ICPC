#include <bits/stdc++.h>
using namespace std;
#define maxn 1'000'000'7
bool is_prime[maxn];
void eratosthenes(int n)
{
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j++)
                is_prime[j] = 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;

    return 0;
}