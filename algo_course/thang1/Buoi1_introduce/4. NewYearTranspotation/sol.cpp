#include <iostream>
int a[30005];
int n, t;

int main()
{
    std::cin >> n >> t;
    for (int i = 1; i <= n - 1; i++)
    {
        std::cin >> a[i];
    }
    int p = 1;
    while (p < t)
    {
        p = p + a[p];
    }
    if (p == t)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}