#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;
///////////////////////template
const int inf = 200'005;
int a, b, k;
long long ans = 0; //<10^5;T=10^4
int girl[inf], boy[inf];
int countBoys[inf], countGirls[inf];
map<pair<int, int>, int> countPairs;
void initial()
{
    cin >> a >> b >> k;
    ans = 0;
    memset(countBoys, 0, sizeof(countBoys));
    memset(countGirls, 0, sizeof(countGirls));
    FOR(i, 1, k)
    cin >> boy[i];
    FOR(i, 1, k)
    cin >> girl[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        initial();
        FOR(i, 1, k)
        {
            // chọn cặp i, và 1 cặp trc i
            int invalid = countBoys[boy[i]] + countGirls[girl[i]];
            ans += i - 1 - invalid;
            countBoys[boy[i]]++;
            countGirls[girl[i]]++;
        }
        cout << ans << endl;
    }
}
// lỗi gặp phải: số lớn