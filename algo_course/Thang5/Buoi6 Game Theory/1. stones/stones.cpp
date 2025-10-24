#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAXN = 100'005;
int f[MAXN];
vector<int> a;
int n, k;
ll fact[MAXN], inv_fact[MAXN];
void initial()
{
    cin >> n >> k;
    a.resize(n);
    for (int &i : a)
        cin >> i;
}
int main()
{
    initial();
    FOR(i, 1, k)
    for (auto x : a)
        if (i - x >= 0 && f[i - x] == 0)
        {
            f[i] = 1;
            break;
        }
    cout << (f[k] ? "First" : "Second");
}

/* bốc x->a[i] viên khỏi đống. ai k bốc được thì thua

n=2, k=5
2 3
f[i] khả năng thắng khi có i viên
f[0] = 1
f[1] = 0
f[2] = 1
f[3] = 1
f[4] = 1
f[5] = 0
----------------------------------
f[0] = 0; //người 1 bốc trc

xét i: 0->k
    for x:a
        nếu i-x>0 và f[i-x] = 0
            f[i] = 1;
=> f[k]

*/