#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
ll recursion(int N)
{
    if (N == 0)
        return 1;
    return recursion(N - 1) * 2;
}
int main()
{
    int n;
    cin >> n;
    cout << recursion(n);
}