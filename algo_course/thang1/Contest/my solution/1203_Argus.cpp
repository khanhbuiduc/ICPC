#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef long long ll;
int n;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    priority_queue<tiii, vector<tiii>, greater<tiii>> min_heap; //{time,period,ID}
    string command;
    int ID, period;
    while (cin >> command && command != "#")
    {
        cin >> ID >> period;
        min_heap.emplace(period, ID, period);
    }
    int K;
    cin >> K;
    while (K--)
    {
        auto [time, ID, period] = min_heap.top();
        min_heap.pop();
        cout << ID << "\n";
        min_heap.emplace(time + period, ID, period);
    }
    return 0;
}