#include <bits/stdc++.h>
using namespace std;
#define NAME "classes."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
    }
    if (n != 1)
    {
        cnt++;
    }
    return cnt;
}

int main()
{
    int n, a;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        fi >> a;
        if (countDivisors(a) % 2 == 0) // vd: 100=2*2*5*5;count=2
        {
            fo << "1 ";
        }
        else
        {
            fo << "2 ";
        }
    }
}