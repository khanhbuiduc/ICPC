#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
using namespace std;
const int mod = 1'000'000'000;

int g(int x)
{
    long long res = ((1ll * x * x) % mod + 2ll * x + 3) % mod;
    return (int)res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    unordered_map<int, int> track;
    vector<int> store;

    int cur = x;
    int step = 0;

    while (track.find(cur) == track.end())
    {
        track[cur] = step;
        store.push_back(cur);
        cur = g(cur);
        step++;

        if (step == n)
        {
            cout << cur << "\n";
            return 0;
        }
    }

    int curStep = track[cur];
    int cycle_length = step - curStep;

    if (n < curStep)
    {
        cout << store[n] << "\n";
    }
    else
    {
        int pos_in_cycle = (n - curStep) % cycle_length;
        cout << store[curStep + pos_in_cycle] << "\n";
    }

    return 0;
}

/*
Birthday Paradox =  23 người, xác suất có 2 người cùng sinh nhật đã > 50%!

*/

/*
2 -> 30000 -> 2
tính 1 tỉ lần
tỉ % (length) = vị trí trong chu kì.
*/