#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
#define max 1'000'000'000 // đầu bài cho
// thử nghiệm: 10*10; ô ẩn là (2,3) (5,7);
ll ask(int x1, int y1, int x2, int y2)
{
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    fflush(stdout);
    ll ans;
    cin >> ans;
    return ans;
}
int binary_searchx1()
{
    int lo = 1, hi = max;
    int x1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        ll ans = ask(1, 1, mid, max);
        if (ans > 0)
        {
            x1 = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return x1;
}
int binary_searchy1()
{
    int lo = 1, hi = max;
    int y1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        ll ans = ask(1, 1, max, mid);
        if (ans > 0)
        {
            y1 = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return y1;
}
int main()
{
    // freopen("input.txt", "r", stdin),
    // freopen("output.txt", "w", stdout);

    ll ans;
    // tìm x1;
    int x1 = binary_searchx1();
    // tìm y1;
    int y1 = binary_searchy1();
    // tìm y2;
    ans = ask(x1, 1, x1, max);
    int y2 = y1 + ans - 1;
    // tìm x2;
    ans = ask(1, y1, max, y1);
    int x2 = x1 + ans - 1;

    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    // testcase: 10*10; ô ẩn là (2,3) (5,7);
}
/*
    (x1,y1,x2,y2)
    tìm x1 bằng cách tìm xmin nhỏ nhất sao cho (1,xmin,1,1'000'000'000) giao với hình ẩn là dương;
        binary_search(){
            l=1;r=1'000'000'000
            while(l<=r){
                mid=(l+r)/2;
                hỏi (1,mid,1 1'000'000'000)
                nếu nhận đc số ô>0;
                    x1=mid;
                    r=mid-1;
                nếu số ô = 0:
                    l=mid +1;
            }
        }
        O(log(1'000'000))=28 câu hỏi để tìm x1;
    tìm y1 bằng cách tìm ymin nhỏ nhất sao cho (1,1'000'000'000,1,ymin) giao với hình là dương;

    tìm y2: hỏi (x1,x1,1,1'000'000'000) để biết có bao nhiêu ô;
        ví dụ có x ô thì y2 = x + y1;

    tìm x2:
        hỏi (1, 1'000'000'000, 1, 1'000'000'000) để biết diện tích S của hình ẩn;
            (x2-x1+1)*(y2-y1+1)=S => x2=(S/(y2-y1+1))-1+x1
        c2: hỏi (1,1'000'000'000,y1,y1); để biết 1 cột có bao nhiêu ô;
            ví dụ có x ô thì x2 = x + x1;
*/