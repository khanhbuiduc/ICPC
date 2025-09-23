#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;

const int maxN = 1000000;
int isPrime[maxN + 1];
long long n;
vector<int> store;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++; // ước i
            if (i * i != n)
                cnt++; // ước n/i (khác i)
        }
    }
    return 0;
}

/*
ví dụ: 10000 = 2 * 5000 = 4* 2500 = 8 * 1250= ... = 100 * 100;
for đơn giản.
cnt = 0;
for i: 1-> căn n;
    nếu n chia hết i cnt++
    nếu i*i!=n cnt++;

độ phức tạp O(căn n)
*/