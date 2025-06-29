// bài này có trick hay hơn là in ra list arr bằng sàng eratosthenes < 10'000'000'
#include <bits/stdc++.h>
using namespace std;
vector<bool> is_prime;
vector<int> prime;
int n, k;
void eratosthenes()
{
    is_prime.assign(n + 1, true);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
}
void genArrPrime()
{
    prime.push_back(0);
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime.push_back(i);
    }
}
long long countSegment()
{
    long long sum = 0;
    int numsPrime = prime.size();
    int L = 1, R = k;

    while (R < numsPrime)
    {
        long long cur = (long long)(prime[L] - prime[L - 1]) * (n + 1 - prime[R]);
        sum += cur;
        L++;
        R++;
    }

    return sum;
}
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> k;
    eratosthenes();
    genArrPrime();
    if ((int)prime.size() < k)
    {
        cout << 0;
        return 0;
    }
    cout << countSegment();
    return 0;
}