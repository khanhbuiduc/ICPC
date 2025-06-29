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
    int N, M;

    // while (cin >> N >> M && (N || M))
    // {
    //     int total = N + M, num;
    //     map<int, int> s;
    //     while (total--)
    //     {
    //         cin >> num;
    //         s[num]++;
    //     }
    //     int count = 0;
    //     for (const auto &[key, val] : s)
    //         if (val > 1)
    //             count++;
    //     cout << count << "\n";
    // }
    while (cin >> N >> M && (N || M))
    {
        int total = N + M, num, i = N + M;
        unordered_set<int> s;
        while (i--) // i:1->tota;
        {
            cin >> num;
            s.insert(num);
        }
        int count = total - s.size(); // số lượng = số lượng hao hụt do trùng số trong set;
        cout << count << "\n";
    }
}