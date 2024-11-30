#include <bits/stdc++.h>
using namespace std;

//================================================
int64_t M;
void multiply(vector<vector<__int128_t>> &mat1,
              vector<vector<__int128_t>> &mat2)
{
    __int128_t x = (mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0]) % M;
    __int128_t y = (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1]) % M;
    __int128_t z = (mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0]) % M;
    __int128_t w = (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1]) % M;

    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}
void matrixPower(vector<vector<__int128_t>> &mat1, int64_t n)
{
    if (n == 0 || n == 1)
        return;
    vector<vector<__int128_t>> mat2 = {{1, 1}, {1, 0}};

    matrixPower(mat1, n / 2);

    multiply(mat1, mat1);
    if (n % 2 != 0)
    {
        multiply(mat1, mat2);
    }
}

int64_t nthFibonacci(int64_t n)
{
    if (n <= 1)
        return n;

    vector<vector<__int128_t>> mat1 = {{1, 1}, {1, 0}};
    matrixPower(mat1, n - 1);

    return mat1[0][0] % M;
}
int main()
{
    freopen("gcd.inp", "r", stdin);
    freopen("gcd.out", "w", stdout);
    int64_t a, b;
    cin >> a >> b >> M;
    // int64_t findGcd = gcd(nthFibonacci(a), nthFibonacci(b));
    int64_t findGcd = nthFibonacci(__gcd(a, b));
    int64_t balance = findGcd;
    cout << balance;
    return 0;
}