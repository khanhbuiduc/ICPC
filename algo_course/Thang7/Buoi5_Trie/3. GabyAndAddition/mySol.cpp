#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= (_b); i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= (_a); i--) // Fixed i-- instead of i
#define FORE(i, a) for (auto i : a)
using namespace std;
typedef long long ll;
int cal[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int n;
string a[1000'005];
int maxlength = 0;
const int mod = 1000000007;
template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else
        return false;
}
struct TrieNode
{
    TrieNode *child[10];
    bool isEnd;
    TrieNode()
    {
        FOR(i, 0, 9) { child[i] = NULL; }
        isEnd = false;
    }
};

void addString(string &s, TrieNode *root)
{
    TrieNode *p = root;
    int cnt0 = maxlength - (int)s.size();
    // thêm 0 vào đầu cho đủ chữ số
    while (cnt0--)
    {
        if (p->child[0] == NULL)
            p->child[0] = new TrieNode();
        p = p->child[0];
    }
    for (char c : s)
    {
        if (p->child[c - '0'] == NULL)
            p->child[c - '0'] = new TrieNode();
        p = p->child[c - '0'];
    }
    p->isEnd = true;
}

ll getmax(string &s, TrieNode *root)
{
    string paddedS = s;
    while (paddedS.size() < maxlength)
        paddedS = "0" + paddedS;

    ll res = 0;
    TrieNode *p = root;

    for (char c : paddedS)
    {
        int digit = c - '0';
        FORD(expect, 9, 0)
        {
            int need = (expect - digit + 10) % 10;
            if (p->child[need])
            {
                (res *= 10) += expect;
                p = p->child[need];
                break;
            }
        }
    }
    return res;
}

ll getmin(string &s, TrieNode *root)
{
    string paddedS = s;
    while (paddedS.size() < maxlength)
        paddedS = "0" + paddedS;

    ll res = 0;
    TrieNode *p = root;

    for (char c : paddedS)
    {
        int digit = c - '0';
        FOR(expect, 0, 9)
        {
            int need = (expect - digit + 10) % 10;
            if (p->child[need])
            {
                (res *= 10) += expect;
                p = p->child[need];
                break;
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    TrieNode *root = new TrieNode();

    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        maximize(maxlength, (int)a[i].size());
    }

    // thêm số đầu vào trie
    addString(a[1], root);

    ll maxVal = 0, minVal = 1e18;
    FOR(i, 2, n)
    {
        maximize(maxVal, getmax(a[i], root));
        minimize(minVal, getmin(a[i], root));
        addString(a[i], root);
    }

    cout << minVal << ' ' << maxVal;
    return 0;
}