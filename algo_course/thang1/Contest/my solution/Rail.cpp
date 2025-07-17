#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<int> B(n);
        while (cin >> B[0] && B[0])
        {
            for (int i = 1; i < n; i++)
                cin >> B[i];
            // solution
            int bi = 0;
            stack<int> st;
            for (int i = 1; i <= n; i++)
            {
                if (i == B[bi])
                {
                    bi++;
                    // Kiểm tra xem có thể pop từ stack không
                    while (!st.empty() && bi < n && st.top() == B[bi])
                    {
                        st.pop();
                        bi++;
                    }
                    continue;
                }
                st.push(i);
            }
            cout << ((bi == n) ? "Yes" : "No") << endl;
            // solution
        }
        cout << endl;
    }
}

// for i: 1->n
// 	nếu: a[i]==B[idxB]
// 		idxB++;
// 		khi stack.top()==B[idxB]
// 			stack.pop();
// 			idxB++;
// 	stack.push(a[i]);
// nếu idxB == B.length thì YES
// else NO