#include <bits/stdc++.h>
using namespace std;
int coutPrime(int x)
{
    int c = 0;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            c++;
            x /= i;
        }
    }
    if (x > 1)
        c++;
    return c;
}
int main()
{
    freopen("classes.inp", "r", stdin);
    freopen("classes.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    for (int i : a)
    {
        if (coutPrime(i) % 2 == 0)
        {
            cout << "1" << " ";
        }
        else
        {
            cout << "2" << " ";
        }
    }
}