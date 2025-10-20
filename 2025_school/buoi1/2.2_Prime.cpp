/*
2.2. Cho số nguyên dương N (N≤109)
    a) Phân tích N thành thừa số nguyên tố
    b) Đếm số ước của N
    c) Tính tổng các ước của N
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> factors;
// Hàm phân tích N thành các thừa số nguyên tố
void primeFactorization(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1)
    {
        factors.push_back({n, 1});
    }
}

// Hàm đếm số lượng ước của N
int countDivisors()
{
    int count = 1;
    for (auto [p, a] : factors)
    {
        count *= (a + 1);
    }
    return count;
}

// Hàm tính tổng các ước của N
long long sumDivisors()
{
    long long sum = 1;
    for (auto [p, a] : factors)
    {
        long long termSum = 0;
        long long power = 1;
        for (int i = 0; i <= a; ++i)
        {
            termSum += power;
            power *= p;
        }
        sum *= termSum;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> factors = primeFactorization(n);

    cout << "Phân tích thừa số nguyên tố:" << endl;
    for (const auto &factor : factors)
    {
        cout << factor.first << "^" << factor.second << " ";
    }
    cout << endl;
    cout << "Số lượng ước: " << countDivisors(factors) << endl;
    cout << "Tổng các ước: " << sumDivisors(factors) << endl;
    return 0;
}