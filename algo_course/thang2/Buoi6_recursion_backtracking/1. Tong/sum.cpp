#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define lim 300'005 //
typedef pair<int, int> pii;
typedef long long ll;
int a[200'005];
int b[200'005];
int recursion(int N)
{
    if (N == 1)
        return 1;
    return recursion(N - 1) + N;
}
int main()
{
    int n;
    cin >> n;
    cout << recursion(n);
}