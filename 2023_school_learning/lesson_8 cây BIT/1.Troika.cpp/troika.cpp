#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
int n;
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
int ChangeNum(int num)
{
    int i = 0, f = primes[i];
    while (num != 1 && num >= f * f)
    {
        while (num % (f * f) == 0)
        {
            num /= (f * f);
        }
        f = primes[++i];
    }
    return num;
}
int main()
{
    freopen("Troika.inp", "r", stdin);
    freopen("Troika.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    sieve(n);
    map<int, int> nums;
    int num = 1, count = 0;
    while (num <= n)
    {
        int changedNum = ChangeNum(num);
        if (nums[changedNum] > 0)
        {
            nums[changedNum]++;
        }
        else
            nums[changedNum] = 1;
        num++;
    }
    for (auto pair : nums)
    {
        int second = pair.second;
        if (second > 2)
            count += (second * (second - 1) * (second - 2) / 6);
    }
    cout << count;
}