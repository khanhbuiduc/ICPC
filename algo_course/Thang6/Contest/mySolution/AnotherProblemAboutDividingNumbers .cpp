#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;
/// template
bool isPrime[40'001];
void cal_prime()
{
    FOR(i, 2, 40'000)
    isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 40000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 40000; j += i)
                isPrime[j] = false;
        }
    }
}

int cntprime(int a)
{
    int res = 0;
    for (int i = 2; i * i <= a; i++)
    {
        while (isPrime[i] && a % i == 0)
        {
            res++;
            a /= i;
        }
    }
    if (a > 1)
        res++;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cal_prime();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        int min_div = 0;
        if (a == 1 && b == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        if (a != b && (!(a % b) || !(b % a)))
            min_div = 1;
        else
            min_div = 2;
        int max_div = cntprime(a) + cntprime(b);
        // cout << min_div << ' ' << max_div << endl;
        if (min_div <= k && k <= max_div)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}
// làm 2 số bằng nhau. tối thiểu cần
/*
    min_divi = 2;
    cnt_a ==0; min --;
    cnt_b ==0; min --;

----------
max chẵn, max lẻ:

*/