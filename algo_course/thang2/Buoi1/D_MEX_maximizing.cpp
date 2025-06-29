#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int n;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    map<int, int> s;
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < x; i++)
        s.emplace(i, 0);
    int mex = 0;
    while (n--)
    {
        int ai;
        cin >> ai;
        s[ai % x]++;
        while (s[mex % x] > 0)
        {
            s[mex % x]--;
            mex++;
        }
        cout << mex << "\n";
    }
}

//  mex là minimum non-negative
/*
    [0,0,1,0,2] mex=3
    nhận xét:   1 số có thể tăng hoặc giảm: ai:=ai+x:=ai+2x=...;
                => a:=b khi và chỉ khi a%x=b%x;
                => lập 1 map: lưu trữ số lượng %x dư 1->x-1;
    nhận xét:   mex không giảm khi thêm phần tử mới
    0,0,1,0,2; x=3
    mex=0;
    [0]-> thêm 0 vào map;
        while(map[mex%x]>0) mex++;map[mex%x]--;
        cout>>mex;
    [0,0]-> thêm 0 vào map:
        while(map[mex%x]>0) mex++;map[mex%x]--;
        cout>>mex;

*/