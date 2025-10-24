#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T, N, k, cur;
    cin >> T;
    while (T--)
    {
        cin >> N >> k;
        deque<pii> store; //{value,index}
        // k vị trí đầu
        for (int i = 1; i <= N; i++)
        {
            cin >> cur;
            if (!store.empty() && (i - store.front().ss >= k))
                store.pop_front();
            while (!store.empty() && cur <= store.back().ff)
                store.pop_back();
            store.emplace_back(cur, i);
            if (i >= k)
                cout << store.front().ff << ' ';
        }
        cout << "\n";
    }
}
/*
    đầu bài: arr=3,2,4,1,8,9, tìm min của từng đoạn k
    vd: 3,2,4,1,8,9: nhận xét: số nhỏ hơn đằng trc không có ý nghĩa thì thay đổi:
        - deque: chứa k số đầu và vị trí của nó:==
                - if vị trí đầu cách số đang xét >k;
                    - bỏ front;
                - if số đang xét < số cuối
                    - bỏ số cuối và thêm số đang xét vào cuối
            - in ra deque.front();
*/