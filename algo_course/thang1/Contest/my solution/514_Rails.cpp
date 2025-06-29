#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long long ll;
int n;
void check(vector<int> &row)
{
    int ri = 0;
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.push(i);
        while (!s.empty() && s.top() == row[ri])
        {
            s.pop();
            ri++;
        }
    }
    if (s.empty())
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    while (cin >> n && n)
    {
        vector<vector<int>> B;
        int Bi;
        while (cin >> Bi && Bi)
        {
            vector<int> row(n);
            row[0] = Bi;
            for (int i = 1; i < n; i++)
            {
                cin >> row[i];
            }
            B.push_back(row);
        }

        for (auto row : B)
            check(row);
        cout << "\n";
    }
}
/*không có ràng buộc gì trong bài
    chuyến tàu đi từ A đến station và đến B;
    A: đc sắp xếp từ 1->N
    đi qua station và đc sắp xếp lại thành B
    khi toa ra A thì k đc vào lại, vào B thì k đc ra lại
    A: 1 2 3 4 5
    station:
        1 2 3 4 5
    2 1 4 3 5
    max: 2:
    B: 5 4 1 2 3
solution:
    for i: 1->n
        stack.push(i)
        while(stack.top=bi)
            stack.pop()
            bi++;
        if(stack.top>bi) cout<<NO
    cout<<yes
    //lưu trữ vector B và stack s;



*/