#include <bits/stdc++.h>
using namespace std;
#define NAME "prime."

ifstream fi(NAME "inp");
ofstream fo(NAME "out");

vector<int> primes;

void sieve(int size)
{
    bitset<10000010> was;
    was.set();
    was[0] = was[1] = 0;
    for (int i = 2; i <= size; i++)
        if (was[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= size; j += i)
                was[j] = 0;
        }
}

vector<int> primeFactors(int N) // 100=2*2*5*5
{
    vector<int> vc;
    int idx = 0, f = primes[idx];
    while (N != 1 && N >= f * f)
    {
        while (N % f == 0)
        {
            N /= f;
            vc.push_back(f);
        }
        f = primes[++idx];
    }
    if (N != 1)
        vc.push_back(N);
    return vc;
}

int main()
{

    sieve(10000);
    int n;
    fi >> n;
    vector<int> pF = primeFactors(n);
    for (int i = 0; i < pF.size(); ++i)
    {
        fo << pF[i] << " ";
    }
    fo << endl;
}