#include <bits/stdc++.h>
using namespace std;
#define NAME "classes."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
    if (n != 1)
        cnt++;
    return cnt;
}

int main()
{
    int n, a;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        fi >> a;
        fo << (countDivisors(a) % 2 ? '1' : '2') << ' ';
    }
}