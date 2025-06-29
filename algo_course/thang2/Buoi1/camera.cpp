#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
bool hasCam[100'001];
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k, r;
    cin >> n >> k >> r;
    // Read initial camera positions
    for (int i = 0; i < k; i++)
    {
        int pos;
        cin >> pos;
        hasCam[pos] = 1;
    }
    // Count cameras in first window [1,r]
    int countCam = 0;
    for (int i = 1; i <= r; i++)
        countCam += hasCam[i];
    int addedCam = 0;

    // Ensure first window has at least 2 cameras
    if (countCam < 2)
    {
        for (int i = r; i >= 1 && countCam < 2; i--)
            if (!hasCam[i])
            {
                hasCam[i] = true;
                countCam++;
                addedCam++;
            }
    }
    // Slide window through remaining houses [l,i]
    for (int i = r + 1; i <= n; i++)
    {
        int l = i - r + 1;
        countCam = countCam - hasCam[l - 1] + hasCam[i];
        if (countCam < 2)
        {
            hasCam[i] = 1;
            countCam++;
            addedCam++;
        }
    }
    cout << addedCam;
}
/*
    nhận xét: xét lần lượt 4 mà liên tiếp l->r:
        - nếu camera<2: thì thêm camera vào r, hoặc r-1;

*/