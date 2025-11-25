#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;
int a[100'005];
vector<int> res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int f = 0;
    FOR(i, 1, n)
    {
        cin >> a[i];
        f ^= a[i];
    }
    //
    if (f == 0)
    {
        cout << '0';
        return 0;
    }
    FOR(i, 1, n)
    {
        if ((f ^ a[i]) <= a[i])
        {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (int i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
}
/*
n đống sỏi
    2 người chơi lần lượt bốc sỏi.
    đống thứ i có a[i] viên:
        người bốc sỏi: bốc 1->a[i] viên trong đống i
        người bốc cuối là người chiến thắng
in ra đống sỏi người đầu bốc đc là chiến thắng
----------------------------------------------------
trò chơi NIM:
f = a1^a2^a3^...^an

nếu f = 0: người 1 luôn ở thế chẵn
nếu f > 0; người 1 có cách để đưa người 2 về thế chẵn
*/
/*
n đống sỏi
    2 người chơi lần lượt bốc sỏi.
    đống thứ i có a[i] viên:
        người bốc sỏi: bốc 1->a[i] viên trong đống i
        người bốc cuối là người chiến thắng
in ra đống sỏi người đầu bốc đc là chiến thắng
----------------------------------------------------
trò chơi NIM:
f = a1^a2^a3^...^an

nếu f = 0: người 1 luôn ở thế chẵn
nếu f > 0; người 1 có cách để đưa người 2 về thế chẵn



*/