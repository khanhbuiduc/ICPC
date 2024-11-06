#include <bits/stdc++.h>
using namespace std;
ifstream fi("input.txt");
ofstream fo("output.txt");
int main()
{
    int n, C;
    fi >> n >> C;
    int arr[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int ai;
        fi >> ai;
        arr[i] = ai;
    }
    sort(arr, arr + n);
    for (int ai : arr)
    {
        C -= ai;
        if (C < 0)
        {
            fo << count;
            return 0;
        }
        count++;
    }
    fo << count;
}