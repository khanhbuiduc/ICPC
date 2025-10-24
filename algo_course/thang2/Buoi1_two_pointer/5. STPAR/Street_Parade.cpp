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
    while (cin >> n && n)
    {
        int ai;
        int p = 1;
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> ai;
            while (!s.empty() && s.top() == p)
            {
                s.pop();
                p++;
            }
            if (ai != p)
                s.push(ai);
            else
                p++;
        }
        while (!s.empty() && s.top() == p)
        {
            s.pop();
            p++;
        }
        if (s.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

/*
    P:1->n;
    stack: hẻm


*/