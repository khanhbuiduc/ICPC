// cho L,R <= 1e6 in ra các số nguyên tố trong đoạn [L,R]
#include <bits/stdc++.h>
using namespace std;
bool isPrime[1000001];
void sieve(int n)
{
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int main()
{
    int L, R;
    cin >> L >> R;
    sieve(R);
    for (int i = L; i <= R; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}