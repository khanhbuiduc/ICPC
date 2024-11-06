#include <iostream>
using namespace std;

int GCD_recursion(int a, int b)
{ //  Great Common Divisor function with recursion.

    if (b == 0)
    {
        return a;
    }
    else
    {
        return GCD_recursion(b, a % b);
    }
}

int LCM(int a, int b)
{ //  Least Common Multiplier function.

    return abs(a * b) / GCD_recursion(a, b);
}

int main()
{
    printf("GCD - a = 18, b = 27 - %d\n", GCD_recursion(18, 27));
    printf("LCM - a = 12, b = 21 - %d\n", LCM(12, 21));
}
