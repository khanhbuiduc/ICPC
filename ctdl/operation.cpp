#include <iostream>

long long ceil_division(long long a, long long b)
{
    return (a + b - 1) / b;
}

int main()
{
    long long a = 1000000005;
    long long b = 4;
    long long result = ceil_division(a, b);                       // floor_division làm tròn xuống;
    std::cout << a << " / " << b << " = " << result << std::endl; // Output: 1000000005 / 4 = 250000002
    return 0;
}
