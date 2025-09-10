#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int arr[200005][11];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, b;
        cin >> n >> b;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= b; j++)
                cin >> arr[i][j];

        // tính tổng tiền tố từng cột
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= b; j++)
                arr[i][j] += arr[i - 1][j];
        // mảng D: arr [r][j] -  arr[r][j+1]  = arr [l-1][j]-arr[l-1][j+1]
        map<vector<int>, int> D;
        for (int i = 0; i <= n; i++)
        {
            vector<int> row;
            for (int j = 1; j < b; j++)
                row.push_back(arr[i][j] - arr[i][j + 1]);
            D[row]++;
        }
        // tính tổng sum+=total*( total-1)/2
        int sum = 0;
        for (auto &[row, nums] : D)
        {
            sum += nums * (nums - 1) / 2;
        }
        cout << sum << "\n";
    }
}