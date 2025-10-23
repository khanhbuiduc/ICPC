// lỗi sai khi làm bài này. prexor[l..r] = prexor[r] - prexor[l-1]
// mà k cho prexor[0] vào.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
int n;
int a[200'005], preXor[200'005]; // a[i] <=10^9 < 2^30
struct trieNode
{
    trieNode *node[2];
    trieNode()
    {
        node[0] = NULL;
        node[1] = NULL;
    }
};
void addNum(int num, trieNode *&root)
{
    trieNode *p = root;
    FORD(bit, 30, 0)
    {
        if (num & (1 << bit))
        {
            if (p->node[1] == NULL)
                p->node[1] = new trieNode();
            p = p->node[1];
        }
        else
        {
            if (p->node[0] == NULL)
                p->node[0] = new trieNode();
            p = p->node[0];
        }
    }
}
int findNum(int num, trieNode *&root) // tìm res để res^num lớn nhất
{
    trieNode *p = root;
    int res = 0;
    FORD(bit, 30, 0)
    {
        // a = 0 ưu tiên b = 1, và ngược lại.
        if (num & (1 << bit)) //==1
        {
            if (p->node[0] != NULL)
            {
                p = p->node[0];
                continue;
            }
            res += (1 << bit);
            p = p->node[1];
        }
        else // num[i] == 0
        {
            if (p->node[1] != NULL)
            {
                p = p->node[1];
                res += (1 << bit);
                continue;
            }
            p = p->node[0];
        }
    }
    return res;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n) { cin >> a[i]; }
    FOR(i, 1, n) { preXor[i] = preXor[i - 1] ^ a[i]; }
    trieNode *root = new trieNode();
    addNum(preXor[0], root);
    int maxXor = 0;
    FOR(r, 1, n)
    {
        int curMaxXor = preXor[r] ^ findNum(preXor[r], root);
        maxXor = max(maxXor, curMaxXor);
        addNum(preXor[r], root);
    }
    cout << maxXor;
}
/*
// tự phân tích
cho n. tìm max xor sum[sub arr của a[1..n]]
1 = 0 0 0 1
5 = 0 1 0 1
9 = 1 0 0 1
xor = 1 1 0 1 = 13
---
prefixXor[i] = prefixXor[i-1]^a[i]
--
xor (a[l..r]) = prefixXor[r] ^ prefixXor[l-1]
tìm max (prefixXor[r] ^ prefixXor[l-1])
--------------------tle---------------------
-----------------tối ưu bằng trie-----------
với mỗi r:
    r[i] = 1 => ưu tiên l chứa 0
    r[i] = 0 => ưu tiên l chứa 1
=> cấu trúc trie phù hợp tìm.
*/
