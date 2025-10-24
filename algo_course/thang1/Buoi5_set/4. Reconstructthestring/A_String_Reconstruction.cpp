#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;

struct hint
{
    string str;
    vector<int> positions;
};

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<hint> hints;
    int Q;
    cin >> Q;
    int lengthS = 0;
    while (Q--)
    {
        vector<int> positions;
        string str;
        int nums;
        cin >> str >> nums;
        for (int i = 0; i < nums; ++i)
        {
            int pos;
            cin >> pos;
            positions.push_back(pos - 1);
            lengthS = max(lengthS, pos - 1 + (int)str.size());
        }
        hints.push_back({str, positions});
    }

    string result(lengthS, 'a');
    set<int> S;
    for (int i = 0; i < lengthS; ++i)
    {
        S.insert(i);
    }

    for (auto &hint : hints)
    {
        string &str_hint = hint.str;
        for (auto pos : hint.positions)
        {
            while (true)
            {
                auto it = S.lower_bound(pos);
                if (it != S.end() && *it - pos < (int)str_hint.size())
                {
                    result[*it] = str_hint[*it - pos];
                    S.erase(it);
                }
                else
                {
                    break;
                }
            }
        }
    }

    cout << result;
}

/*
Q=4;
a 4 1 5 9 10
aa 3 1 9 10
bc 2 3 7
b 2 3 7

lengS=11;
set={1,2,3,4,5,6,7,8,9,10,11}
nhập: hints {str,list index}
lengthS=max(index+length string -1)

set{1->lengthS}//chứa vị trí chưa đc thay đổi

với mỗi hint: tìm xem có vị trí vào chưa có phù hợp(nhỏ nhất >= index_hint)
;index_store - length < hint_length THÌ
*/
