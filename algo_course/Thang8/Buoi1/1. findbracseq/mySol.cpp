#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
string s;
struct Node
{
    int open;
    int close;
    int pairs;
};
Node mergeNode(Node left, Node right)
{
    int matched = min(left.open, right.close);
    int open = left.open + right.open - matched;
    int close = left.close + right.close - matched;
    int pairs = left.pairs + right.pairs + matched;
    return {open, close, pairs};
}
Node solve(int L, int R)
{
    if (L == R)
    {
        if (s[L] == '(')
            return {1, 0, 0};
        else if (s[L] == ')')
            return {0, 1, 0};
        else
            return {0, 0, 0};
    }
    int mid = (L + R) / 2;
    Node left = solve(L, mid);
    Node right = solve(mid + 1, R);
    return mergeNode(left, right);
}
int main()
{
    cin >> s;
    // cout << s;
    cout << (solve(0, (int)s.size() - 1).pairs * 2);
    return 0;
}
/*
không dùng stack. dùng mersort tree.
cho sâu s = "aa()...". tìm dãy con dài nhất ngoặc đúng.
merge_sort tree: chia cây thành 2 phần rồi gép lại.
---
*/
// 1 node: "{" dư, "}" dư, "{}" hợp lệ
// btcs:
// nếu s[i] == "{" return {1,0,0}
// nếu s[i] == "}" return {0,0,0}
// nếu s[i] != thì return {0,0,0}

// duyệt
// mid = (L + R)/2
// leftNode = mergeTree(L,mid);
// rightNode= mergeTree(mid+1,R)
// open  = leftNode.open + rightNode.open - min(leftNode.open, rightNode.close)
// close = leftNode.close + rightNode.close - min(leftNode.open, rightNode.close)
//  pairs = leftNode.pairs + rightNode.pairs + min(leftNode.open, rightNode.close)
// return {open, close, pairs}