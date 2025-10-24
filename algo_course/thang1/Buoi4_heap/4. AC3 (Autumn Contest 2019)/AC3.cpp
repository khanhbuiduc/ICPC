#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
int main()
{
    int T, N, K;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        int li, ri;
        int maxPoint = 0;
        vector<pii> segs; //{li,ri};
        for (int i = 0; i < N; i++)
        {
            cin >> li >> ri;
            segs.emplace_back(li, ri);
        }
        sort(segs.begin(), segs.end());
        priority_queue<int, vector<int>, greater<int>> p; // store ri để lấy ra min
        for (int i = 0; i < N; i++)
        {
            p.push(segs[i].ss);
            if (i + 1 >= K) // từ vị trí K
            {
                ri = p.top();
                li = segs[i].ff;
                maxPoint = max(maxPoint, ri - li + 1);

                p.pop();
            }
        }
        cout << maxPoint << "\n";
    }
}
/*
    1 10
    5 8
    3 9
    1 15
    số điểm giao ở 4 đoạn = min(ri) - max(li)+ 1
    1: cố định li bằng cách sort các đoạn:
    1 10-
    1 15-
    2 3
    3 9-
    4 9-
    5 8
    5 11
    6 12
    2. dùng priority queue để store ri: lấy min 4 số đang dùng
            p:10,15,3,9: li=3,ri=3,max=1
        - khi xét số tiếp theo {4,9}:
            p: 10,15,9,9//loại ri min đi rồi thêm ri mới vào
            li=4,ri=9,max=6
        cứ thế tiếp tục...

*/